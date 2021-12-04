#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <chrono>
#include <limits>
#include <math.h>
#include <vector>

std::mutex m;

void pcout(const std::string& str){
    for(size_t i = 0; i < 3; ++i){
        std::lock_guard<std::mutex> lg(m);
        std::cout << "Thread #: " << std::this_thread::get_id()
                 <<"\t" << str << std::endl;
    }
}

void unmutexedCout(const std::string& str){
    for(size_t i = 0; i < 3; ++i){
        std::cout << "Thread #: " << std::this_thread::get_id()
                 <<"\t" << str << std::endl;
    }
}

int count{1};
int serialNumber{1'000'000};

void printProgress(){
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        if(count == serialNumber){
            break;
        }
        std::cout << "Execution progress: "
                  <<int((double)count / serialNumber * 100)
                  << "%" << std::endl;
    }
}

void primeNumber(){
    if(serialNumber == 1){
        std::cout << "Prime = 2" << std::endl;
    }
    for(int i = 3; i <= std::numeric_limits<int>::max(); (i += 2)){
        bool isPrime = true;
        for(int j = 3; j <= sqrt(i) ; j+=2){
            if(i % j == 0){
                isPrime = false;
               break;
            }
        }
        if(isPrime){
            count++;
            if(count == serialNumber){
                std::cout << "Prime = " << i << std::endl;
                break;
            }
        }
    }
}

int main()
{
    //=========================================
    {
        std::cout << "With thread cout:" << std::endl;
        for(size_t i = 0; i < 3; ++i){
            std::thread tr1(pcout, "Blah");
            std::thread tr2(pcout, "Blah");
            std::thread tr3(pcout, "Blah");
            tr1.join();
            tr2.join();
            tr3.join();
        }
        std::cout << "With non thread cout:" << std::endl;
        std::thread tr4(unmutexedCout, "Blah");
        std::thread tr5(unmutexedCout, "Blah");
        std::thread tr6(unmutexedCout, "Blah");
        tr4.join();
        tr5.join();
        tr6.join();
    }
    //=========================================
    {
        std::thread threadForPrime(primeNumber);
        std::thread threadForProgress(printProgress);
        threadForPrime.join();
        threadForProgress.join();
    }
    //=========================================
    {
        srand(time(0));

        std::vector<int> home;

        std::thread threadOwner([&home](){
            for(size_t i = 0; i < 10; ++i){
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                std::cout << "Owner came home\n";
                std::lock_guard<std::mutex> lg(m);
                {
                    int item{ rand() % 10'000 };
                    home.emplace_back(item);
                    std::cout << "Item: " << item << " was put to home\n";
                }
            }
        });
        std::thread threadTheif([&home](){
            for(size_t i = 0; i < 10; ++i){
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::cout << "Theif came home\n";
                std::lock_guard<std::mutex> lg(m);
                {
                    if(home.size()){
                        std::vector<int>::iterator max{home.begin()};
                        for(auto it = home.begin() + 1; it != home.end(); ++it){
                            if(*max < *it){
                                max = it;
                            }
                        }
                        std::cout << "Item " << *max << " was stolen\n";
                        home.erase(max);
                    }
                    else{
                        std::cout << "Theif leaves, cause nothing to steal\n";
                    }
                }
         }});
        threadOwner.join();
        threadTheif.join();
    }
    //=========================================
    return 0;
}
