#include <clocale>
#include <iostream>
#include <cmath>
#include <cstdint>

class Power {
private:
    int first_num = 0;
    int second_num;
public:
    Power() : first_num(0), second_num(0) {};
    void set(int first, int second) {
        first_num = first;
        second_num = second;
    }
    void calculate() {
       std::cout << pow(first_num, second_num) << std::endl;       
    }
};

class RGBA {
private:
    uint8_t m_red =  0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;    
public:
    RGBA(uint8_t red , uint8_t green, uint8_t blue, uint8_t alpha) : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}    
    void print() {
        std::cout << "m_red = " << int(m_red) << std::endl << "m_green = " << int(m_green) << std::endl << "m_blue = " << int(m_blue) << std::endl << "m_alpha = " << int(m_alpha) << std::endl;
    }
};

class Stack {
private:
    int arr[10];
    int stack_len;
public:
    Stack() : stack_len(0) {};
    void reset() {
        for (size_t i = 0; i < 10; i++) {
            arr[i] = 0;
        }
        stack_len = 0;
    }

    bool push(int value) {
        if (stack_len < 10) {
            arr[stack_len] = value;
            stack_len++;
            return true;
        }
        return false;
    }

    int pop() {
        if (stack_len == 0) {
            std::cout << "Стек пуст!" << std::endl;
            return 0;
        }
        stack_len--;
        return arr[stack_len];
    }

    void print() {
        std::cout << "Stack contains: ";
        for (size_t i = 0; i < stack_len; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");    

    {
        std::cout << "№1. Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. Еще создать два метода : один с именем set, который позволит присваивать значения переменным, второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию." << std::endl;
        Power p;
        p.set(2,11);
        p.calculate();
    }

    {
        std::cout << "№2. Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов." << std::endl;
        RGBA a(55, 45, 56, 3);        
        a.print();
    }

    {
        std::cout << "№3.Написать класс, который реализует функциональность стека. Класс Stack должен иметь: " << std::endl;
        std::cout << "-private-массив целых чисел длиной 10;" << std::endl;
        std::cout << "-private целочисленное значение для отслеживания длины стека;" << std::endl;
        std::cout << "-public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;" << std::endl;
        std::cout << "-public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;" << std::endl;
        std::cout << "-public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;" << std::endl;
        std::cout << "-public-метод с именем print(), который будет выводить все значения стека." << std::endl;

        Stack stack;
        stack.reset();
        stack.print();

        stack.push(3);
        stack.push(7);
        stack.push(5);
        stack.print();

        std::cout << stack.pop() << std::endl;
        stack.print();

        std::cout << stack.pop() << std::endl;
        std::cout << stack.pop() << std::endl;
        stack.print();
    }                 
    return 0;
}