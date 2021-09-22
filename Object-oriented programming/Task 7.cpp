#include <clocale>
#include <iostream>
#include <memory>

#pragma region Task_1
class Date {
private:
public:
    int m_Day;
    int m_Month;
    int m_Year;
    Date(int m_Day, int m_Month, int m_Year) : m_Day(m_Day), m_Month(m_Month), m_Year(m_Year) {}
    Date() : m_Day(0), m_Month(0), m_Year(0) {}
    int getMonth(){
        return m_Month;
    }
    int getDay(){
        return m_Day;
    }
    int getYear(){
        return m_Year;
    }    
    friend std::ostream& operator<<(std::ostream& os, const Date m_Date);
};

std::ostream& operator<<(std::ostream& os, const Date m_Date) {
    os << "Date: " << m_Date.m_Day << "/" << m_Date.m_Month << "/" << m_Date.m_Year;
    return os;
}
#pragma endregion 

#pragma region Task_2

Date& compareDates(std::shared_ptr<Date>& d1, std::shared_ptr<Date>& d2) {
    if (d1->getYear() > d2->getYear()) {
        return *d1;
    }
    if(d1->getYear() < d2->getYear()) {
        return *d2;
    }
    if (d1->getMonth() > d2->getMonth()) {
        return *d1;
    }
    if(d1->getMonth() < d2->getMonth()) {
        return *d2;
    }
    if (d1->getDay() > d2->getDay()) {
        return *d1;
    }
    if(d1->getDay() < d2->getDay()) {
        return *d2;
    }
    return *d1;
}

void swapValues(std::shared_ptr<Date>& d1, std::shared_ptr<Date>& d2) {
    std::shared_ptr<Date> date1 = d1;
    d1 = d2;
    d2 = date1;
}


#pragma endregion 

int main()
{
    setlocale(LC_ALL, "Russian");
    {
        std::cout << "№1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям. Перегрузите оператор вывода для данного класса. " << std::endl;
        std::cout << "Создайте два ""умных"" указателя today и date. Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы доступа к полям класса Date, " << std::endl;
        std::cout << "а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода. Затем переместите ресурс, которым владеет указатель today в указатель date. " << std::endl;
        std::cout << "Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль." << std::endl;       
        std::shared_ptr<Date> today = std::make_shared<Date>(1,1,1999);
        std::cout << today->getDay() << " ";
        std::cout << today->getMonth() << " ";
        std::cout << today->getYear() << std::endl;
        std::cout << *today;
        std::shared_ptr<Date> date = std::move(today);
        std::cout << *date;
        std::cout << "Указатель today = " << today << std::endl;
        std::cout << "Указатель date = " << date << std::endl;
    }

    {
        std::cout << "№2.По условию предыдущей задачи создайте два умных указателя date1 и date2." << std::endl;
        std::cout << "Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой(сравнение происходит по датам).Функция должна вернуть более позднюю дату." << std::endl;
        std::cout << "Создайте функцию, которая обменивает ресурсами(датами) два умных указателя, переданных в функцию в качестве параметров." << std::endl;
        std::shared_ptr<Date> date1 = std::make_shared<Date>(1,2,3333);
        std::shared_ptr<Date> date2 = std::make_shared<Date>(4,5,6666);
        std::cout << "Исходные значения:" << std::endl;
        std::cout << "date1 - " << *date1 << std::endl;
        std::cout << "date2 - " << *date2 << std::endl;
        std::cout << "Более поздняя дата: " << compareDates(date1, date2) << std::endl;
        swapValues(date1, date2);
        std::cout << "Переставленные значения:" << std::endl;
        std::cout << "date1 - " << *date1 <<std::endl;
        std::cout << "date2 - " << *date2 <<std::endl;
    }  
    return 0;
}