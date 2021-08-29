#include <clocale>
#include <iostream>

const int ARR_SIZE = 100;
char stack[ARR_SIZE];
int cursor = -1;

typedef struct Node{
    int dat; 
    struct Node *next;
}Node;

typedef struct{
    Node *head; 
    int size;    
}List;

int stack_push(char data) {

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

int stack_pop()
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

bool check(const char* arr)
{    
    for (int i = 0; arr[i] != 0; i++)
    {    
        if (arr[i] == '(')
        {
            stack_push(')');
        }
        else if (arr[i] == '[')
        {
            stack_push(']');
        }
        else if (arr[i] == '{')
        {
            stack_push('}');
        } 
        else if ((arr[i] == '}' || arr[i] == ']' || arr[i] == ')') && (cursor != -1) && arr[i] != stack_pop())
        {
            cursor = -1;
            return false;
        }               
    }
    if (cursor < 0) return true;    
    else return false; 
}

void pushToList(List *lst, int data)
{
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->dat = data;
    new_node->next = lst->head;
    lst->head = new_node;
    lst->size++;
}

void PrintList(List *lst)
{
    if (lst->head == nullptr)
    {
        std::cout << "Список пуст!" << std::endl;
        return;
    }
    Node *current = lst->head;   
    do 
    {
        std::cout << "[" << current->dat << "]";       
        current = current->next;
    } 
    while (current != nullptr);   
    std::cout << std::endl;
}

void initList(List *lst)
{
    lst->head = NULL;
    lst->size = 0;
}

void CopyList(List *from, List *to)
{
    int size = from->size;
    Node *current = from->head;    
    while (size != 0)
    {
        for (size_t i = 0; i < size - 1; ++i)
        {
            current = current->next;
        }
        pushToList(to, current->dat);
        size--;
        current = from->head;
    }  
}

bool isSorted(List* lst)
{
    Node* current = lst->head;
    while (current->next != NULL && current->dat > current->next->dat) {        
        current = current->next;
            return true;
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    {
        std::cout << "№1. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{. Например: (2+(2*2)) или [2/{5*(4+7)}]" << std::endl;         
        std::cout << "Cкобочная последовательность () " << (check("()") ? "правильная" : "неправильная") << std::endl;
        std::cout << "Cкобочная последовательность ([])() " << (check("([])()") ? "правильная" : "неправильная") << std::endl;
        std::cout << "Cкобочная последовательность ([{}]) " << (check("([{}])") ? "правильная" : "неправильная") << std::endl;
        std::cout << "Cкобочная последовательность )( " << (check(")(") ? "правильная" : "неправильная") << std::endl;
        std::cout << "Cкобочная последовательность ())({) " << (check("())({)") ? "правильная" : "неправильная") << std::endl;
        std::cout << "Cкобочная последовательность ( " << (check("(") ? "правильная" : "неправильная") << std::endl;
        std::cout << "Cкобочная последовательность ])}) " << (check("])})") ? "правильная" : "неправильная") << std::endl;
        std::cout << "Cкобочная последовательность ([(]) " << (check("([(])") ? "правильная" : "неправильная") << std::endl;
        std::cout << "Cкобочная последовательность [2/{5*(4+7)}] " << (check("[2/{5*(4+7)}]") ? "правильная" : "неправильная") << std::endl;
    }

    {
        std::cout << "№2. Создать функцию, копирующую односвязный список (без удаления первого списка)." << std::endl;
        List first;
        initList(&first);
        List second;
        initList(&second);
        for (size_t i = 0; i < 9; i++)
        {
            pushToList(&first, i);
        }
        PrintList(&first);
        CopyList(&first, &second);
        PrintList(&second);      
    }

    {
        std::cout << "№3. Реализуйте алгоритм, который определяет, отсортирован ли связный список." << std::endl;
        List first;
        initList(&first);        
        for (size_t i = 0; i < 9; i++)
        {
            pushToList(&first, i);
        }
        PrintList(&first);
        std::cout << "Список " << (isSorted(&first) ? "отсортирован" : "не отсортирован") << std::endl;
        pushToList(&first, 7);         
        pushToList(&first, 95);        
        pushToList(&first, 1);
        PrintList(&first);
        std::cout << "Список " << (isSorted(&first) ? "отсортирован" : "не отсортирован") << std::endl;


    }
    return 0;
}

