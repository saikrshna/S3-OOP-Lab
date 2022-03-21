//
// Created by tproh on 26-01-2022.
//

#include <iostream>

std::string get()
{
    std::string str;
    std::cin >> str;

    return str;
}

void write(const std::string& str)
{
    std::cout << str;
}

int main()
{
    write(get());
    std::cin.peek();
    std::cin.ignore(10, '\n');
    std::cin.putback('a')
}