//
// Created by Rohit T P on 02-11-2021.
//

#include <iostream>
#include <cmath>

class Triangle {
private:
    float a{}, b{}, c{};

public:
    Triangle() = default;

    bool isValid() const {
        return (a + b > c) && (a + c > b) && (b + c > a) && a > 0 && b > 0 && c > 0;
    }

    float getArea() const
    {
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void print() const
    {
        std::cout << "Side-1 : " << a << "\tSide-2 : " << b << "\tSide-3 :" << c << std::endl;
    }

    friend std::istream &operator>>(std::istream &is, Triangle &triangle) {
        is >> triangle.a >> triangle.b >> triangle.c;
        return is;
    }
};

int main()
{
    Triangle triangle = Triangle();

    std::cout << "Enter sides of the triangle";
    std::cin >> triangle;

    triangle.print();

    if(!triangle.isValid())
        std::cout << "Invalid Triangle";
    else
        std::cout << "Valid Triangle with area = " << triangle.getArea();

    return 0;
}