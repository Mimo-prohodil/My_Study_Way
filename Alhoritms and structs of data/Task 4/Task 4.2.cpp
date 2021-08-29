#include <clocale>
#include <iostream>
#include <ctime>
const int ARR_SIZE = 25;
int stack[ARR_SIZE];
int cursor = -1;
const int GRAPH_SIZE = 6;
int visited[GRAPH_SIZE] = { 0 };
int graph_matrix_first[GRAPH_SIZE][GRAPH_SIZE] = {
        //  0  1  2  3  4  5 
    /*0*/ { 0, 1, 0, 0, 0, 1},
    /*1*/ { 1, 0, 1, 1, 1, 0},
    /*2*/ { 0, 1, 0, 1, 0, 0},
    /*3*/ { 0, 0, 1, 0, 1, 0},
    /*4*/ { 0, 1, 0, 1, 0, 1},
    /*5*/ { 1, 0, 0, 0, 1, 0},
};
int graph_matrix_second [GRAPH_SIZE][GRAPH_SIZE] = {
        //  0  1  2  3  4  5 
    /*0*/ { 0, 1, 0, 1, 0, 1},
    /*1*/ { 1, 0, 1, 0, 1, 0},
    /*2*/ { 0, 1, 0, 1, 0, 0},
    /*3*/ { 0, 0, 1, 0, 1, 0},
    /*4*/ { 0, 0, 0, 1, 0, 1},
    /*5*/ { 1, 0, 0, 0, 1, 0},
}; 

int stack_push(int data){
    if (cursor < ARR_SIZE){
        stack[++cursor] = data;
        return true;
    }
    else{
        std::cout << "Стэк переполнен!" << std::endl;
        return -1;
    }
}

int stack_pop(){
    if (cursor != -1){
        return stack[cursor--];
    }
    else{
        std::cout << "Стэк пуст!" << std::endl;
        return -1;        
    }
}

void print_arr(int arr[GRAPH_SIZE][2]) {
    for (size_t i = 0; i < GRAPH_SIZE; i++)
    {
        std::cout << arr[i][0] << "/" << arr[i][1] << std::endl;
    }
}

void sortinsert(int arr[GRAPH_SIZE][2])
{
    int temp0, temp1, pos;
    for (int i = 1; i < GRAPH_SIZE; i++)
    {
        temp0 = arr[i][0];
        temp1 = arr[i][1];
        pos = i - 1;
        while (pos >= 0 && arr[pos][1] > temp1)
        {
            arr[pos + 1][1] = arr[pos][1];
            arr[pos + 1][0] = arr[pos][0];
            pos--;
        }
        arr[pos + 1][1] = temp1;
        arr[pos + 1][0] = temp0;
    }
}

void depth_travers(int peak) {
    stack_push(peak);     
    visited[peak] = 1;
    while (cursor > -1){
        int current = stack_pop();
        std::cout << current << " ";
        for (size_t i = 0; i < GRAPH_SIZE; i++){
            if (graph_matrix_first[current][i] == 1 && visited[i] != 1){
                stack_push(i);
                visited[i] = 1;
            }
        }       
    }
    std::cout << std::endl;
}

void cycle_travers_recursive(int peak, int arr[GRAPH_SIZE][2]) {    
    visited[peak] = 1;
    for (size_t i = 0; i < GRAPH_SIZE; i++) {
        if (graph_matrix_second[peak][i] == 1) {
            arr[i][0] = i;
            arr[i][1]++;            
            if (visited[i] != 1) {
                cycle_travers_recursive(i, arr);
            }            
        }
    }       
}

void cycle_travers(int peak, int arr[GRAPH_SIZE][2]) {
    for (size_t i = 0; i < GRAPH_SIZE; i++) {
        for (size_t j = 0; j < GRAPH_SIZE; j++) {
            if (graph_matrix_second[i][j] == 1) {
                arr[i][0] = i;
                arr[i][1]++;
            }
        }
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    std::srand(std::time(0));
    {
        /*std::cout << "№1. Реализовать обход в глубину с использованием стека" << std::endl;
        depth_travers(1);
        clean_arr(visited, GRAPH_SIZE);  */  
    }

    {
        std::cout << "№2. Моделируем робот поисковой системы. Дан готовый простой граф с циклическими связями.";
        std::cout << "Нужно обойти этот граф двумя способами и подсчитать количество ссылок на каждый из узлов графа(полустепень захода) :" << std::endl;        
        std::cout << "В конце обхода вывести два получившихся списка всех узлов в порядке уменьшения количества ссылок на них." << std::endl;
        std::cout << "- обход графа рекурсивной функцией(с подсчётом только смежных со стартовой вершин)" << std::endl;
        int link_arr[GRAPH_SIZE][2] = { 0 };
        cycle_travers_recursive(1, link_arr);
        sortinsert(link_arr);
        print_arr(link_arr);
        for (size_t i = 0; i < GRAPH_SIZE; i++) {
            visited[i] = 0;
        }
        for (size_t i = 0; i < GRAPH_SIZE; i++){
            for (size_t j = 0; j < 2; j++){
                link_arr[i][j] = 0;
            }
        }
        std::cout << "- обход графа по матрице смежности(с подсчётом всех вершин графа)" << std::endl;
        cycle_travers(1, link_arr);
        sortinsert(link_arr);
        print_arr(link_arr);
    }
    return 0;
}




