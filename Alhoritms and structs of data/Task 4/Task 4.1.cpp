#include <clocale>
#include <iostream>
#include <ctime>

typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
}tree_node;

tree_node* tree_add(tree_node* t, int data) {    
    if (t == nullptr) {
        t = (tree_node*)malloc(sizeof(tree_node));
        t->key = data;
        t->left = nullptr;
        t->right = nullptr;
    }
    else if (t->key > data) {
        t->left = tree_add(t->left, data);
    }
    else
    {
        t->right = tree_add(t->right, data);
    }
    return t;
}

void tree_print(tree_node* tree)
{
    if (tree) {
        std::cout << tree->key;
        if (tree->left || tree->right) {
            std::cout << "(";
            if (tree->left)
                tree_print(tree->left);
            else
                std::cout << "*";
            std::cout << ",";

            if (tree->right)
                tree_print(tree->right);
            else
                std::cout << "*";
            std::cout << ")";
        }
    }    
}

int check_balance_recursive(tree_node* tree){
    if (tree == nullptr){        
        return 0;
    }
    int leftside = check_balance_recursive(tree->left);
    int rightside = check_balance_recursive(tree->right);
    if (leftside == -1|| rightside == -1 || abs(leftside - rightside) > 1){        
        return -1; 
    }  
    return ((leftside > rightside) ? leftside : rightside) + 1;
}

bool check_balance(tree_node* tree) {    
    return check_balance_recursive(tree) != -1;
}

bool bin_search(tree_node* tree, int data){
    if (tree == nullptr){
        return false;
    }
    if (tree->key == data){
        return true;
    }
    if (tree->key != data){
        if (data > tree->key){
            return bin_search(tree->right, data);           
        }
        else{
            return bin_search(tree->left, data);            
        }
    }
    else {
        return true;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::srand(std::time(0));

    {
        std::cout << "№1.Написать функцию проверяющую является ли переданное в неё бинарное дерево сбалансированным и написать программу, которая:" << std::endl;
        std::cout << " - создаст[50] деревьев по[10000] узлов и заполнит узлы случайными целочисленными значениями; " << std::endl;
        std::cout << " - рассчитает, какой процент из созданных деревьев является сбалансированными." << std::endl;       
        int balance_count = 0;
        for (size_t i = 0; i < 50; i++){
            tree_node* tree = nullptr;
            tree = tree_add(tree, 250);            
            for (size_t j = 0; j < 10000; j++){
                tree_add(tree, std::rand() % 500);                
            }                    
            balance_count += check_balance(tree);           
        }      
        std::cout << "Сбалансированно " << balance_count * 2 << "% деревьев." << std::endl; 
    }

    {
        std::cout << "№2. Написать рекурсивную функцию бинарного поиска в дереве хранящемся в узлах, а не в массиве." << std::endl;
        tree_node* tree = nullptr;
        tree = tree_add(tree, 250);
        tree_add(tree, 100);
        tree_add(tree, 50);
        tree_add(tree, 300);
        tree_add(tree, 150);
        tree_add(tree, 270);
        tree_add(tree, 400);
        tree_add(tree, 2);
        tree_add(tree, 1);
        tree_print(tree);
        std::cout << std::endl;
        std::cout << "Введите элемент: ";
        int num;
        std::cin >> num;      
        std::cout << "Элемент " << num << (bin_search(tree, num) ?  " найден" : " не найден") << std::endl;
    }
    return 0;
}
