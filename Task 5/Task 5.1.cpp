#include <clocale>
#include <iostream>
#include <ctime>

int hash_sum(char* string) {

    int sum = 0;
    int i = 0;
    while (string[i] != '\0') {
        sum += *string;
        i++;
    }
    return sum;
}

void geed_sum(int* sum, int* coin, const int size, int money) {
    int k = 0;
    int current = 0;
    for (size_t i = 0; i < size; i++){       
        while (money - current >= coin[i]) {
            current += coin[i];
            sum[k] = coin[i];
            k++;
            if (money == current) {
                return;
            }
        }
    }
    std::cout << "Разбиение по представленным достоинтсвам не удалось." << std::endl;
    return;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    std::srand(std::time(0));

    {
        std::cout << "№1. Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов." << std::endl;
        std::cout << std::endl;
        std::cout << "Введите строку для хэширования: " << std::endl;
        char string[300];
        std::cin.getline(string, 300);
        std::cout << "Результат хэширования: " << hash_sum(string) << std::endl;
    }

    {
        std::cout << "№2. Имеются монеты номиналом 50, 10, 5, 2, 1 коп. Напишите функцию которая минимальным количеством монет наберет сумму 98 коп." << std::endl; 
        std::cout << "Для решения задачи используйте “жадный” алгоритм." << std::endl;
        const int SIZE = 5;
        int coin[SIZE] = { 50, 10, 5, 2, 1 };
        int sum[100] = { 0 };
        int money = 98;
        geed_sum(sum, coin, SIZE, money);        
        std::cout << money << " = ";
        for (size_t i = 0; i < 100; i++)
        {
            if (sum[i] == 0) {
                break;
            }
            std::cout << sum[i] << " ";
        }
    }
    return 0;
}