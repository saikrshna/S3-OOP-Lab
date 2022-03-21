//
// Created by tproh on 25-01-2022.
//

#include <cmath>
#include <iostream>

class PolarCoordinates {
private:
    double theta, r;

public:

    PolarCoordinates(double r, double theta) {
        this->theta = theta;
        this->r = r;
    }

    PolarCoordinates() = default;

    double getX() const {
        return r * cos(theta);
    }

    double getY() const{
        return  r * sin(theta);
    }

    friend std::ostream &operator<<(std::ostream &out, PolarCoordinates &p) {
        return out << "r = " << p.r << " theta = " << p.theta;
    }

    friend std::istream &operator>>(std::istream &is, PolarCoordinates &p) {
        return is >> p.r >> p.theta;
    }

};

class RectangularCoordinates {
private:
    double x, y;

public:

    RectangularCoordinates(double x, double y) {
        this->x = x;
        this->y = y;
    }

    RectangularCoordinates() = default;

    double getR() const
    {
        return sqrt(x*x + y*y);
    }

    double getTheta() const
    {
        return atan(y/x);
    }

    explicit operator PolarCoordinates() const {
        return {getR(), getTheta()};
    }

    RectangularCoordinates &operator=(PolarCoordinates &p) {
        this->x = p.getX();
        this->y = p.getY();

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, RectangularCoordinates &p) {
        return out << "( " << p.x << " , " << p.y << " )";
    }

    friend std::istream &operator>>(std::istream &is, RectangularCoordinates &p) {
        return is >> p.x >> p.y;
    }
};


int main()
{
    PolarCoordinates p{};
    RectangularCoordinates r{};

    std::cout << "Enter radius and angle : ";
    std::cin >> p;

    std::cout << "Enter x and y coordinates : ";
    std::cin >> r;

    PolarCoordinates pFromR = (PolarCoordinates) r;
    RectangularCoordinates rFromP{};
    rFromP = p;

    std::cout << p << " in rectangular coordinates = " << rFromP << std::endl;
    std::cout << r << " in polar coordinates = " << pFromR << std::endl;

    return 0;
}