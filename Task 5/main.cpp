#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <list>
#include <set>

#include <fstream>
#include <locale>
#include <codecvt>
#include <io.h>
#include <fcntl.h>

template<typename T>
void printUnique(const T& begin,const T& end){
    std::unordered_set<std::string> set;
    for(auto i = begin; i != end; ++i){
        set.emplace(*i);
    }
    for(const auto& it : set){
        std::cout << it << ' ';
    }
    std::cout << std::endl;
}

int main(){
    {
        std::vector<std::string> vec{"first str",
            "first str", "second str" };
        printUnique(vec.begin(), vec.end());

        std::list<std::string> list{"first str",
            "first str", "second str" };
        printUnique(list.begin(), list.end());

        std::multiset<std::string> set{"first str",
            "first str", "second str" };
        printUnique(set.begin(), set.end());
    }

    {
        _setmode(_fileno(stdout), _O_U16TEXT);
        _setmode(_fileno(stdin),  _O_U16TEXT);
        _setmode(_fileno(stderr), _O_U16TEXT);

        //===================================================
        // Для считывания из файла и работы с кодировкой utf-8

//        std::ifstream file("sampleText");
//        std::string buff;
//        std::wstring result;
//        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
//        while (!file.eof()) {
//                std::getline(file, buff);
//                result.append(converter.from_bytes(buff));
//        }
//        auto cmp = [](const std::wstring &a, const std::wstring &b)
//            { return a.size() > b.size(); };
//        std::set<std::wstring, decltype(cmp)> sortSet(cmp);

//        std::wstring buff2;
//        for(const auto& it : result){
//            buff2 += it;
//            if(it == L'.' ||it == L'!' || it == L'?' ){
//                sortSet.emplace(buff2);
//                buff2.clear();
//            }
//        }

        //===================================================
        // Для считывания из потока ввода и работы с кодировкой utf-8

        std::wstring inpStr;
        std::wstring inpBuff;
        std::cout << "Enter some sentence" << std::endl;
        std::cout << "To exit, enter 0" << std::endl;
        while(true){
            std::getline(std::wcin, inpBuff);
            std::wcout << inpBuff << std::endl;
            inpStr.append(inpBuff);
            if(inpBuff == L"0"){
                break;
            }
            inpBuff.clear();
        }
        auto cmp = [](const std::wstring &a, const std::wstring &b)
            { return a.size() >= b.size(); };
        std::set<std::wstring, decltype(cmp)> sortSet(cmp);

        // Если в компараторе  использовать >, то одинаковые строки игнорируются
        // Решается использованием multiset или заменой знака на >=
//        auto cmp = [](const std::wstring &a, const std::wstring &b)
//        { return a.size() > b.size(); };
//        std::multiset<std::wstring, decltype(cmp)> sortSet(cmp);

        std::wstring buff;
        for(const auto& it : inpStr){
            buff += it;
            if(it == L'.' ||it == L'!' || it == L'?' ){
                sortSet.emplace(buff);
                buff.clear();
            }
        }
        //===================================================

        for(const auto& it : sortSet){
            std::wcout << it << std::endl;
        }
    }
    return 0;
}
