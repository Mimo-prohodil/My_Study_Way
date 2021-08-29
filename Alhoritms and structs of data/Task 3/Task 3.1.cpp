#include <clocale>
#include <iostream>
#include <ctime>
#define K int;
const int ARR_SIZE = 5;
int stack[ARR_SIZE];
int cursor = -1;

typedef struct {
    int priority;
    int data;
} Node;
Node* arr[ARR_SIZE];
int head;
int tail;
int items;

void intiation()
{
    for (size_t i = 0; i < ARR_SIZE; ++i)
    {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}
void insert(int priority, int data)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->priority = priority;       
    if (items < ARR_SIZE)
    {
        arr[tail++] = node;
        items++;
    }
    else
    {
        std::cout << "Очередь заполнена!" << std::endl;
        return;
    }    
}
Node* remove()
{
    if (items == 0)
    {
        std::cout << "Очередь пуста!" << std::endl;
        return NULL;
    }
    int max = arr[0]->priority;
    int idx = 0;
    for (int i = 1; i < items; ++i)
    {        
        if (arr[i]->priority > max)
        {
            max = arr[i]->priority;
            idx = i;
        }        
    }
    Node* tmp = arr[idx];
    while (idx < items)
    {        
        arr[idx] = arr[idx + 1];
        idx++;
    }
    items--;
    tail--;
}
void printq()
{
    std::cout << "[";
    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (arr[i] == NULL)
        {
            std::cout << "[*, *]";
        }
        else
        {
            printf("[%d, %d]", arr[i]->priority, arr[i]->data);
        }
    }
    std::cout << "]" << std::endl;
}
void convert(int conv_num)
{
    if (conv_num != 0)
        convert(conv_num / 2);
    else return;

    std::cout << conv_num % 2;
    
    return;
}
int stack_input(int data){    
    
    if (cursor < ARR_SIZE)
    {
        stack[++cursor] = data;
        return true;
    }
    else
    {
        std::cout << "Стэк переполнен!" << std::endl;
        return -1;
    }
}
int stack_output()
{
    if (cursor != -1)
    {
        return stack[cursor--];
    }
    else
    {
        std::cout << "Стэк пуст!" << std::endl;
        return -1;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");   
    {
        std::cout << "№1.Описать очередь с приоритетным исключением" << std::endl;
        intiation();
        printq();
        insert(1, 10);
        insert(2, 10);
        insert(3, 19);
        insert(4, 20);
        insert(5, 6);
        printq();
        for (size_t i = 0; i < 3; ++i)
        {
            Node* n = remove();
        }
        printq();
        insert(5, 60);
        insert(5, 67);
        printq();
        /*Вывод программы с этой проверкой:
        [[*, *][*, *][*, *][*, *][*, *]]
        [[1, 10][2, 10][3, 19][4, 20][5, 6]]
        [[1, 10][2, 10][*, *][*, *][*, *]]
        [[1, 10][2, 10][5, 60][5, 67][*, *]]*/
    }

    {
        std::cout << "№2. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека." << std::endl;            
        stack_input(55);
        stack_input(235);
        stack_input(566);
        stack_input(12);        
        while (cursor != -1)
        {
            convert(stack_output());
            std::cout << std::endl;
        }
    }

    return 0;
}

