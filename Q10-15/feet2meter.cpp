//
// Created by tproh on 25-01-2022.
//

//
// Created by tproh on 25-01-2022.
//

#include <cmath>
#include <iostream>

class FeetInch {
private:
    double inch;
    int feet;

    void validate()
    {
        int extra = (int) (this->inch / 12);
        this->feet += extra;
        this->inch -= extra * 12;
    }

public:

    FeetInch(int r, double theta) {
        this->inch = theta;
        this->feet = r;

        validate();
    }

    FeetInch() = default;

    double getMeters() const {
        return (feet + inch/12) / 3.28;
    }

    friend std::ostream &operator<<(std::ostream &out, FeetInch &p) {
        return out << p.feet << " Foot " << p.inch << " inches";
    }

    friend std::istream &operator>>(std::istream &is, FeetInch &p) {
        is >> p.feet >> p.inch;
        p.validate();

        return is;
    }

};

class Meter {
private:
    double length;

public:

    explicit Meter(double x) {
        this->length = x;
    }

    Meter() = default;

    int getFeet() const
    {
        return (int) (this->length * 3.28);
    }

    double getInch() const
    {
        return (this->length * 39.37) - (getFeet() * 12);
    }

    explicit operator FeetInch() const {
        return {getFeet(), getInch()};
    }

    Meter &operator=(FeetInch &p) {
        this->length = p.getMeters();
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, Meter &p) {
        return out <<  p.length << " Meters";
    }

    friend std::istream &operator>>(std::istream &is, Meter &p) {
        return is >> p.length;
    }
};


int main()
{
    FeetInch p{};
    Meter r{};

    std::cout << "Enter feet and inches : ";
    std::cin >> p;

    std::cout << "Enter meters : ";
    std::cin >> r;

    FeetInch pFromR = (FeetInch) r;
    Meter rFromP{};
    rFromP = p;

    std::cout << p << " = " << rFromP << std::endl;
    std::cout << r << " = " << pFromR << std::endl;

    return 0;
}