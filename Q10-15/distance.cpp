#include <iostream>

using namespace std;

class Distance {
    int feet, inch;

public:
    Distance() {
        feet = 0;
        inch = 0;
    }

    void get_value() {
        cout << "Enter a distance in feet \n";
        cin >> feet;
        cout << "Enter a distance in inch \n";
        cin >> inch;
    }

    void display_data() const {
        cout << endl << "Feet value = " << feet << endl;
        cout << "Inch value = " << inch << endl;
    }

    Distance operator+(Distance &obj) const {
        Distance demo;

        demo.feet = feet + obj.feet;
        demo.inch = inch + obj.inch;

        if (demo.inch >= 12) {
            demo.feet += (demo.inch / 12);
            demo.inch = demo.inch % 12;
        }

        return demo;
    }

    friend string operator<(Distance &, Distance &);
};

string operator<(Distance &obj1, Distance &obj2) {
    if (obj1.feet < obj2.feet) {
        return "distance 1 less than distance 2\n";
    } else if (obj1.feet == obj2.feet && obj1.inch < obj2.inch) {
        return "distance 1 less than distance 2\n";
    } else if (obj1.feet > obj2.feet) {
        return "distance 1 greater than distance 2\n";
    } else if (obj1.feet == obj2.feet && obj1.inch > obj2.inch) {
        return "distance 1 great than distance 2\n";
    } else {
        return "distance 1 equal to distance 2\n";
    }
}

int main() {
    Distance obj1, obj2;

    obj1.get_value();
    obj1.display_data();

    obj2.get_value();
    obj2.display_data();

    Distance obj3 = obj1 + obj2;
    cout << "sum of distance\n";
    obj3.display_data();

    string out = obj1 < obj2;
    cout << out;
    return 0;
}