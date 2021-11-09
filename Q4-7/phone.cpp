//
// Created by Rohit T P on 02-11-2021.
//

#include <iostream>

struct Phone {
    short unsigned int area;
    short unsigned int exchange;
    short unsigned int number;

    void fix(Phone &phone)
    {
        phone.area *= (phone.area < 999) - (phone.area > 999);
        phone.exchange *= (phone.exchange < 999) - (phone.exchange > 999);
        phone.number *= (phone.number < 9999) - (phone.number > 9999);
    }

    bool isValid(Phone &phone)
    {
        return phone.area < 999 && phone.exchange < 999 &&  phone.number < 9999 &&
                phone.area > 100 && phone.exchange > 100 && phone.number > 1000;
    }
};

int main() {
    Phone myNumber{100, 200, 1234};
    Phone yourNumber{};

    std::cout << "Enter your area code, exchange, and number :";
    std::cin >> yourNumber.area >> yourNumber.exchange >> yourNumber.number;

    yourNumber.fix(yourNumber);

    if(!yourNumber.isValid(yourNumber))
        return std::cout << "Invalid number", 1;

    std::cout << "My Number : ";
    std::cout << "(" << myNumber.area << ") " << myNumber.exchange << "-" << myNumber.number << "\n";

    std::cout << "Your Number : ";
    std::cout << "(" << yourNumber.area << ") " << yourNumber.exchange << "-" << yourNumber.number << "\n";

    return 0;
}