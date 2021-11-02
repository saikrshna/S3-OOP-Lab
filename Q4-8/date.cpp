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

    friend Date operator++(Date &date) {
        if (date.day >= (max_days[date.month] + (date.month == 2 && isLeap(date.year)))) {
            date.month = date.month++ % 12;
            date.day = 1;
            date.year += date.month == 1;
        } else
            date.day++;

        return date;
    }

    friend std::ostream &operator<<(std::ostream &out, Date &date) {
        return out << date.day << "/ " << date.month << "/ " << date.year;
    }

    friend std::istream &operator>>(std::istream &is, Date &date) {
        is >> date.day >> date.month >> date.year;
        return is;
    }
};

int main() {
    Date date1 = Date(31, 12, 2020);
    Date date2 = Date();
    Date next;

    std::cout << "Enter a date :";
    std::cin >> date2;

    std::cout << "Date 1 : " << date1 << " " << date1.isValid() << std::endl;
    next = ++date1;
    std::cout << " Next Date : " << next << std::endl << std::endl;

    std::cout << "Date 2 : " << date2 << " " << date2.isValid() << std::endl;
    next = ++date2;
    std::cout << " Next Date : " << next << std::endl;

    return 0;
}
