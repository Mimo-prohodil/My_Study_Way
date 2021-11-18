#include <clocale>
#include <iostream>
#include <ctime>

void print_arr(int* arr, int arr_size);
void blocksort(int* arr, int arr_size);
void sortinsert(int* arr, int first, int last);
void imp_quick_sort(int* arr, int first, int last);
int mid_sort(int mid, int first, int last);

int main()
{
    setlocale(LC_ALL, "Russian");
    std::srand(std::time(0));

    {
        std::cout << "№1.Описать в коде улучшенный алгоритм быстрой сортировки" << std::endl;
        int arr_size;
        std::cout << "Введите число элементов массива: " << std::endl;
        std::cin >> arr_size;
        int* arr = new int[arr_size];
        for (int i = 0; i < arr_size; i++)
        {
            arr[i] = std::rand() % 10;
        }
        print_arr(arr, arr_size);
        imp_quick_sort(arr, 0, arr_size - 1);
        std::cout << std::endl;
        print_arr(arr, arr_size);
        delete[] arr;
    }

    {
        std::cout << "№2.Сортировать в массиве целых положительных чисел только чётные числа, нечётные оставив на своих местах при помощи алгоритма блочной сортировки, то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 6 5 9 8 8 7 3]" << std::endl;

        int arr_size;
        std::cout << "Введите число элементов массива: " << std::endl;
        std::cin >> arr_size;
        int* arr = new int[arr_size];
        for (int i = 0; i < arr_size; i++)
        {
            arr[i] = std::rand() % 10;
        }
        print_arr(arr, arr_size);
        blocksort(arr, arr_size);
        print_arr(arr, arr_size);
        delete[] arr;
    }
    return 0;
}
int mid_sort(int mid, int first, int last)
{
    if (mid >= first && mid >= last)
    {
        return mid;
    }
    else if (first >= mid && first >= last)
    {
        return first;
    }
    else
    {
        return last;
    }
}

void imp_quick_sort(int* arr, int first, int last)
{
    if ((last - first) < 10)
    {
        sortinsert(arr, first, last);
        return;
    }
    int temp;
    int i = first;
    int j = last;
    int mid = (first + last) / 2;
    int x = arr[mid_sort(mid, first, last)];
    do
    {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        }
        
    } while (i <= j);
    if (i < last) imp_quick_sort(arr, i, last);
    if (first < j) imp_quick_sort(arr, first, j);
}

void sortinsert(int* arr, int first, int last)
{
    int temp, pos;
    for (int i = first; i < last + 1; i++)
    {
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

void blocksort(int* arr, int arr_size)
{
    int temp;
    for (int i = 0; i < arr_size; i++) {
        for (int j = arr_size - 1; j > i; j--) {
            if (arr[i] % 2 == 0 && arr[j] % 2 == 0 && arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void print_arr(int* arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}