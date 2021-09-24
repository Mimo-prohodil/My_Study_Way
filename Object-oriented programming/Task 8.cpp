#include <clocale>
#include <iostream>
#include <stdexcept>

#pragma region Task_1
template<typename T> T div(T op1, T op2) {
    if (op2 == 0) {        
        throw std::runtime_error("DivisionByZero");
    }
    return op1 / op2;
}

#pragma endregion 

#pragma region Task_2

class Ex {
private:
    int x;
public:
    Ex(int x) : x(x){}
    friend std::ostream& operator<<(std::ostream& os, const Ex m_Ex);
};

std::ostream& operator<<(std::ostream& os, const Ex m_Ex) {
    os << m_Ex.x;
    return os;
}

class Bar {
private:
    int y;
public: 
    Bar() : y(0) {}
    void setY(int a) {
        y = a;
    }
    int getY() {
        return y;
    }
};

#pragma endregion 

#pragma region Task_3

class OffTheField {
private:
    int position;
    int direction;
public:
    OffTheField(int position, int direction) : position(position), direction(direction) {}
    int getPosition() {
        return position;
    }
    int getDirection() {
        return direction;
    }
};

class IllegalCommand {
private:
    int position;
    int direction;
public:
    IllegalCommand(int position, int direction) : position(position), direction(direction) {}
    int getPosition() {
        return position;
    }
    int getDirection() {
        return direction;
    }
};

class Robot {
private:
    int field[10][10];
    int** position;
    char direction;
public:
    Robot() : direction('0') {
        field[10][10] = { 0 };
        position = new field;
    }
    void setDirection(char a) {
        direction = a;
    }
    void setPosition(int a, int b) {
        position[a][b] = 1;
    }
    void movement(char dir, int&& pos) {
        if (dir == 'w') {
            pos[][]
        }
    }
};

#pragma endregion 

int main()
{
    setlocale(LC_ALL, "Russian");

    /*{
        std::cout << "№1. Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero," << std::endl;
        std::cout << "если второй параметр равен 0. В функции main выводить результат вызова функции div в консоль, а также ловить исключения. " << std::endl;
        try {
            std::cout << "12 / 3 = " << div<int>(12, 3) << std::endl;
            std::cout << "13 / 0 = " << div<int>(13, 0) << std::endl;
        }
        catch (std::runtime_error e) {
            std::cout << e.what() << std::endl;
        }
    }*/

    /*{
        std::cout << "№2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, инициализирующий x значением параметра. " << std::endl;
        std::cout << " Написать класс Bar, хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a. " << std::endl;
        std::cout << " Если y + a > 100, возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a. В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n." << std::endl;
        std::cout << " Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения." << std::endl;
        Bar b; 
        int n;
        do {
            std::cout << "Введте число :";
            std::cin >> n;            
            try {
                if ((b.getY() + n) > 100) {
                    throw Ex(n * b.getY());
                }
                b.setY(n);
            }
            catch(Ex){
                std::cout << Ex(n * b.getY()) << std::endl;
            }
        } while (n != 0);
    }*/

    {
        std::cout << "№3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на соседнюю позицию." << std::endl;
        std::cout << "Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне)." << std::endl;
        std::cout << "Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения. Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов," << std::endl;
        std::cout << "а также выводящую подробную информацию о всех возникающих ошибках." << std::endl;
        Robot r;


    }

    return 0;
}