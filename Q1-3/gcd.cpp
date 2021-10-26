//
// Created by Rohit TP on 26-10-2021.
//

#include <iostream>

int main() {
    int a, b;

    std::cout << "Enter the numbers to find GCD of\n";
    std::cin >> a >> b;

    if (!((a - b) * a * b))
        return std::cout << "GCD = " << (a != 0) * a + (a == 0) * b, 0;

    if (std::min(a, b) - a) {
        a += b;
        b = a - b;
        a = a - b;
    }

    for (int tmp; a; b = tmp) {
        tmp = a;
        a = b % a;
    }

    std::cout << "GCD = " << b;
    return 0;
}