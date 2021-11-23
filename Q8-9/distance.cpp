//
// Created by Rohit on 23-11-2021.
//

#include <iostream>

struct Point {
    int x;
    int y;
};

inline double distance(Point a, Point b, Point c) {
    int abx = a.x - b.x;
    int aby = a.y - b.y;
    int acx = a.x - c.x;
    int acy = a.y - c.y;
    int bcx = b.x - c.x;
    int bcy = b.y - c.y;

    return std::min(std::min(sqrt(abx * abx + aby * aby), sqrt(acx * acx + acy * acy)), sqrt(bcx * bcx + bcy * bcy));
}

int main()
{
    Point a{},b{},c{};

    std::cout << "Enter the vertices of the triangle." << std::endl;
    std::cin >> a.x >> a.y;
    std::cin >> b.x >> b.y;
    std::cin >> c.x >> c.y;

    std::cout << "Minimum distance = " << distance(a,b,c);
}