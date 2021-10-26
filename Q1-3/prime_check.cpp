//
// Created by Rohit TP on 26-10-2021.
//

#include <iostream>

int main() {
    int number;

    std::cout << "Enter the number to check :";
    std::cin >> number;

    for (int i = 2; i < sqrt(number); i++)
        if (!(number % i))
            return std::cout << "The number is not prime", 0;

    std::cout << "The entered number is prime";
    return 0;
}