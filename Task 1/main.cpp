#include <iostream>
#include <variant>
#include "PhoneBook.h"


int main() {
    std::ifstream file("PhoneBook.txt");    
    PhoneBook book(file);
    std::cout << book;

    std::cout << "------SortByPhone-------" << std::endl;
    book.SortByPhone();
    std::cout << book;

    std::cout << "------SortByName--------" << std::endl;
    book.SortByName();
    std::cout << book;

    std::cout << "-----GetPhoneNumber-----" << std::endl;
    auto print_phone_number = [&book](const std::string& surname) {
        std::cout << surname ;
        auto answer = book.GetPhoneNumber(surname);
        if (std::get<0>(answer).empty()) {
            std::cout << std::get<1>(answer);
        }
        else {
            std::cout << std::get<0>(answer);
            std::cout << std::endl;
        }
    };
    print_phone_number("Ivanov");
    std::cout << std::endl;
    print_phone_number("Petrov");

    std::cout << "----ChangePhoneNumber----" << std::endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, 
        PhoneNumber{ 7, 123, "15344458", std::nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, 
        PhoneNumber{ 16, 465, "9155448", 13 });
    std::cout << book;

    return 0;
}
