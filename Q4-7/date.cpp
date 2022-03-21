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

    Date() = default;

    Date operator+(int days) {
        Date date = *this;

        while (days--)
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
    Date date;
    Date next;

    int days;

    std::string str;

    std::cout << str.max_size();
    std::cout<<std::endl;
    std::cout << str.capacity();

    std::cout << "Enter a date :";
    std::cin >> date;

    std::cout << "Enter number of days to add: ";
    std::cin >> days;

    next = date + days;

    std::cout << date << " + " << days << " days = " << next << std::endl;

    return 0;
}
