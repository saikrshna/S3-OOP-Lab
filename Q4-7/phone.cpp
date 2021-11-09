//
// Created by Rohit T P on 02-11-2021.
//

#include <iostream>

struct Phone {
    short unsigned int area;
    short unsigned int exchange;
    short unsigned int number;

    void fix()
    {
        area *= (area < 999) - (area > 999);
        exchange *= (exchange < 999) - (exchange > 999);
        number *= (number < 9999) - (number > 9999);
    }

    bool isValid() const
    {
        return area < 999 && exchange < 999 &&  number < 9999 &&
                area > 100 && exchange > 100 && number > 1000;
    }
};

int main() {
    Phone myNumber{100, 200, 1234};
    Phone yourNumber{};

    std::cout << "Enter your area code, exchange, and number :";
    std::cin >> yourNumber.area >> yourNumber.exchange >> yourNumber.number;

    yourNumber.fix();

    if(!yourNumber.isValid())
        return std::cout << "Invalid number", 1;

    std::cout << "My Number : ";
    std::cout << "(" << myNumber.area << ") " << myNumber.exchange << "-" << myNumber.number << "\n";

    std::cout << "Your Number : ";
    std::cout << "(" << yourNumber.area << ") " << yourNumber.exchange << "-" << yourNumber.number << "\n";

    return 0;
}