//
// Created by Rohit TP on 26-10-2021.
//

#include <iostream>

int main() {
    int number;

    std::cout << "Enter the number under which you need the prime :";
    std::cin >> number;

    if (number < 3)
        return std::cout << "No primes less than " << number << " found", 0;

    int *primes = new int[number/2];
    int primes_found = 1;

    primes[0] = 2;

    for (int i = 3; i < number; i++) {
        bool prime = true;

        for (int j = 0; j < primes_found; j++)
            if (i % primes[j] == 0) {
                prime = false;
                break;
            }

        if (prime)
            primes[primes_found++] = i;
    }

    std::cout << "Largest prime < " << number << " = " << primes[primes_found - 1];

    delete[] primes;

    return 0;
}