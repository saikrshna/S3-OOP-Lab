#include<iostream>
#include<cmath>

class shape {
protected:
    float a, b, c, s{}, l{}, b1{}, x{};
    float r{};
public:
    shape() {
        a = 0;
        b = 0;
        c = 0;
    }

    virtual void input() {}

    virtual void validity() {}

    virtual void area() {}

    virtual void perimeter() {}
};

class triangle : public shape {
protected:
    float a1{}, p1{};
public:
    void input() override {
        std::cout << "Enter the dimensions of triangle" << '\n';
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
    }

    void validity() override {
        {
            if (((a + b) > c) && ((b + c) > a) && ((c + a) > b))
                std::cout << "triangle is valid" << '\n';
            else
                std::cout << "invalid" << '\n';
        }
    }

    void area() override {
        s = (a + b + c) / 2;
        a1 = (float) sqrt(s * (s - a)*(s - b)*(s - c));
        std::cout << "Area of triangle =" << a1 << '\n';
    }

    void perimeter() override {
        p1 = a + b + c;
        std::cout << "Perimeter of triangle =" << p1 << '\n';
    }
};

class rectangle : public shape {
protected:
    float a2{}, p2{};
public:
    void area() override {
        std::cout << "Enter the dimensions of rectangle" << '\n';
        std::cin >> l;
        std::cin >> b1;
        a2 = l * b1;
        std::cout << "Area of rectangle =" << a2 << '\n';
    }

    void perimeter() override {
        p2 = 2 * (l + b1);
        std::cout << "Perimeter of rectangle =" << p2 << '\n';
    }
};

class circle : public shape {
protected:
    float a3{}, p3{};
public:
    void area() override {
        std::cout << "Enter the dimensions of circle" << '\n';
        std::cin >> r;
        a3 = (float) 3.14 * r * r;
        std::cout << "Area of circle =" << a3 << '\n';
    }

    void perimeter() override {
        p3 = (float) (2 * 3.14 * r);
        std::cout << "Perimeter of circle =" << p3 << '\n';
    }
};

class square : public shape {
protected:
    float a4{}, p4{};
public:
    void area() override {
        std::cout << "Enter the dimensions of square" << '\n';
        std::cin >> x;
        a4 = x * x;
        std::cout << "Area of square =" << a4 << '\n';
    }

    void perimeter() override {
        p4 = 4 * x;
        std::cout << "Perimeter of square =" << p4 << '\n';
    }
};

int main() {
    shape s1;
    triangle t;
    rectangle r1;
    circle c1;
    square s2;
    shape *ptr;

    ptr = &s1;
    ptr->input();
    ptr->area();
    ptr->perimeter();
    std::cout << "TRIANGLE" << '\n';

    ptr = &t;
    ptr->input();
    ptr->validity();
    ptr->area();
    ptr->perimeter();
    std::cout << "RECTANGLE" << '\n';

    ptr = &r1;
    ptr->area();
    ptr->perimeter();
    std::cout << "CIRCLE" << '\n';

    ptr = &c1;
    ptr->area();
    ptr->perimeter();
    std::cout << "SQUARE" << '\n';

    ptr = &s2;
    ptr->area();
    ptr->perimeter();

    return 0;
}
