//
// Created by Rohit T P on 02-11-2021.
//

#include <iostream>

class Date {
private:
    int year = 0;
    int month = 0;
    int day = 0;

    static bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

public:

    constexpr static const int max_days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    Date(int day, int month, int year) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    Date() = default;

    const char *isValid() const {
        return (this->year > 0 && this->month > 0 && this->day > 0 &&
                this->month < 13 && this->day <= (max_days[this->month] + (this->month == 2 && isLeap(this->year)))) ?
               "Valid" : "Not Valid";
    }

    Date next() {
        if (this->day >= (max_days[this->month] + (this->month == 2 && isLeap(this->year)))) {
            this->month = (this->month + 1) % 12;
            this->day = 1;
            this->year += this->month == 1;
        } else
            this->day++;

        return *this;
    }

    void print() const {
        std::cout << this->day << "/ " << this->month << "/ " << this->year << std::endl << std::endl;
    }

    void read() {
        std::cin >> this->day >> this->month >> this->year;
    }
};

int main() {
    Date date1 = Date(31, 12, 2020);
    Date date2 = Date();

    std::cout << "Enter a date :";
    date2.read();

    std::cout << "Date 1 : " << date1.isValid() << " ";
    date1.print();
    std::cout << " Next Date : ";
    date1.next().print();

    std::cout << "Date 2 : " << date2.isValid() << " ";
    date2.print();
    std::cout << " Next Date : ";
    date2.next().print();

    return 0;
}
