#include <clocale>
#include <iostream>
#include <string>

class Person {
protected:
    int age;
    std::string sex;
    std::string name;
    int weight;    
public:    
    Person(const int age, const std::string sex, const std::string name, const int weight) : age(age), sex(sex), name(name), weight(weight) {};
    void set_age(int setting_age) {
        age = setting_age;        
    }    
    void set_name(int setting_name) {        
        name = setting_name;        
    }
    void set_weight(int setting_weight) {
        weight = setting_weight;
    }
    int get_age() const{
        return age;
    }
    std::string get_sex() const {
        return sex;
    }
    std::string get_name() const {
        return name;
    }
    int get_weight() const {
        return weight;
    }
};
class Student : public Person {
private:
    int year_of_study;
    static int student_counter; 
public:
    Student(const int age, const std::string sex, const std::string name, const int weight, const int year_of_study) : Person(age, sex, name, weight), year_of_study(year_of_study) { student_counter++; };
    void set_year_of_study(int year) {
        year_of_study = year;
    }
    void increaced_year_of_study(int num) {        
         year_of_study += num;        
    }
    int get_year_of_study() const {
        return year_of_study;
    }    
    static int get_student_counter() {
        return student_counter;
    }
    void print() {
        std::cout << "Студент: " << name << " " << sex << " " << weight << " " << age << " " << year_of_study << std::endl;
    }
    ~Student() { student_counter--; };
};

int Student::student_counter = 0;

class Fruit {
private:      
    std::string name;
    std::string color;
public:
    Fruit(const std::string name, const std::string color) : name(name), color(color) {};
    void set_name(std::string name) {
        this->name = name;
    }
    std::string get_name() const {
        return name;
    }
    void set_color(std::string color) {
        this->color = color;
    }
    std::string get_color() const {
        return color;
    }
};
class Apple : public Fruit {
public:
    Apple(std::string color) : Fruit("apple", color) {};
};
class Banana : public Fruit {
public:
    Banana() : Fruit("banana", "yellow") {};
};
class Granny_Smith : public Apple {   
public:
    Granny_Smith() : Apple("green") {
        set_name("Granny Smith apple");
    };
};


int main()
{
    setlocale(LC_ALL, "Russian");

    {
        std::cout << "№1. Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, изменения возраста и веса. Создать производный класс Student (студент), имеющий поле года обучения. Определить методы переназначения и увеличения этого значения. Создать счетчик количества созданных студентов. В функции main() создать несколько студентов. По запросу вывести определенного человека." << std::endl;
        Student student1(10, "male", "Peter", 90, 5);
        Student student2(10, "male", "Vasya", 90, 5);
        Student student3(10, "male", "Prokhor", 90, 5);
        student1.print(); 
    }

    {
        std::cout << "№2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить новый класс GrannySmith, который наследует класс Apple." << std::endl;
        
        Apple a("red");
        Banana b;
        Granny_Smith c;

        std::cout << "My " << a.get_name() << " is " << a.get_color() << ".\n";
        std::cout << "My " << b.get_name() << " is " << b.get_color() << ".\n";
        std::cout << "My " << c.get_name() << " is " << c.get_color() << ".\n";        
    }

    {
        std::cout << "№3. Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование. Сколько будет классов в программе? Какие классы будут базовыми, а какие производными? Продумать реализацию игры с помощью классов и записать результаты." << std::endl;
        //По моему мнению понадобятся: 
        //класс игра с дочерними классом карта и её дочерним классом колода; 
        //класс игрок, унаследованный от игры, с дочерними классами человек и ии;
        //                    игра             
        //               /             \ 
        //          карта              игрок
        //            /               /    \               
        //          колода       человек   ии
    }
    return 0;
}