#include <iostream>

#define TOTAL_WORKING_HOURS 160

class Employee {
protected:
    char name[10]{};
    int empNo{};
    float payRate{};
public:
    Employee() = default;

    void getEmployeeData() {
        std::cout << "Enter the employee details below" << '\n';
        std::cout << "--------------------------------" << '\n';
        std::cout << "Enter the name:" << '\n';
        std::cin >> name;
        std::cout << "Enter employment no." << '\n';
        std::cin >> empNo;
        std::cout << "Enter pay rate:" << '\n';
        std::cin >> payRate;
    }

    virtual float pay() = 0;

    void displayEmployeeData() {
        std::cout << "********" << '\n';
        std::cout << "Name of employee: " << name << '\n';
        std::cout << "Employment No. " << empNo << '\n';
        std::cout << "Pay rate " << payRate << '\n';
        std::cout << "Salary: " << pay() << '\n';
        std::cout << "********" << '\n';
    }
};

class Manager : public Employee {
private:
    bool isSalaried{};
    int workingHours{};
public:
    void getManagerData() {
        std::cout << "If salaried hourly enter 0 else 1:" << '\n';
        std::cin >> isSalaried;
        if (!isSalaried) {
            std::cout << "Enter the total working hours:" << '\n';
            std::cin >> workingHours;
        }
    }

    float pay() override {
        if (isSalaried)
            return payRate * TOTAL_WORKING_HOURS;
        else
            return payRate * (float) workingHours;
    }
};

class Supervisor : public Employee {
private:
    std::string department;
public:
    void getSupervisorData() {
        std::cout << "\n Department: ";
        std::cin >> department;
    }

    float pay() override {
        return payRate * TOTAL_WORKING_HOURS;
    }
};

int main() {
    Manager M1;
    Supervisor S;
    int choice;
    std::cout << "\n **enter details** ";
    std::cout << "\n 1. Manager";
    std::cout << "\n 2. Supervisor";
    std::cout << "\n Enter your choice(1 or 2): ";
    std::cin >> choice;
    switch (choice) {
        case 1:
            M1.getEmployeeData();
            M1.getManagerData();
            M1.displayEmployeeData();
            break;
        case 2:
            S.getEmployeeData();
            S.getSupervisorData();
            S.displayEmployeeData();
            break;
        default:
            std::cout << "\n Oops.....Incorrect Choice!";
    }
    return 0;
}