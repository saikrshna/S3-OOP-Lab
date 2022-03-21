#include<iostream>

#define MAXSIZE 10

class student {
protected:
    int age{};
    long reg_no{};
    std::string name;
public:
    virtual void sort(int n) = 0;
};

class MTech_stud : public student {
protected:
    float gpa;
public:
    MTech_stud() : student() {
        gpa = 0.0;
    }

    void getval() {
        std::cout << "Name :: ";
        std::cin >> name;
        std::cout << "Age :: ";
        std::cin >> age;
        std::cout << "Registration Number :: ";
        std::cin >> reg_no;
        std::cout << "GPA :: ";
        std::cin >> gpa;
    }

    void sort(int n) override {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (this[i].gpa > this[i + 1].gpa) {
                    MTech_stud temp = this[i];
                    this[i] = this[i + 1];
                    this[i + 1] = temp;
                }
                if (this[i].gpa == this[i + 1].gpa) {
                    if ((this[i].name.compare(this[i + 1].name)) < 0) {
                        MTech_stud temp = this[i];
                        this[i] = this[i + 1];
                        this[i + 1] = temp;
                    }
                }
            }
        }
    }

    void display() {
        std::cout << "Name :: " << name << '\n';
        std::cout << "Age :: " << age << '\n';
        std::cout << "Reg No. :: " << reg_no << '\n';
        std::cout << "GPA :: " << gpa << '\n' << '\n';
    }
};

class BTech_stud : public student {
protected:
    float mks;
public:
    BTech_stud() : student() {
        mks = 0.0;
    }

    void getval() {
        std::cout << "Name :: ";
        std::cin >> name;
        std::cout << "Age :: ";
        std::cin >> age;
        std::cout << "Registration Number :: ";
        std::cin >> reg_no;
        std::cout << "Marks :: ";
        std::cin >> mks;
    }

    void sort(int n) override {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (this[i].mks > this[i + 1].mks) {
                    BTech_stud temp = this[i];
                    this[i] = this[i + 1];
                    this[i + 1] = temp;
                }
                if (this[i].mks == this[i + 1].mks) {
                    if ((this[i].name.compare(this[i + 1].name)) < 0) {
                        BTech_stud temp = this[i];
                        this[i] = this[i + 1];
                        this[i + 1] = temp;
                    }
                }
            }
        }
    }

    void display() {
        std::cout << "Name :: " << name << '\n';
        std::cout << "Age :: " << age << '\n';
        std::cout << "Reg No. :: " << reg_no << '\n';
        std::cout << "Marks :: " << mks << '\n' << '\n';
    }
};

int main() {
    student *S;
    BTech_stud B[MAXSIZE];
    MTech_stud M[MAXSIZE];
    int n, x = -1;
    while (x) {
        std::cout << "Choose Programme :: \n";
        std::cout << "1. B.Tech \n";
        std::cout << "2. M.Tech \n";
        std::cout << "Enter 0 to EXIT \n";
        std::cout << "Your Choice :: ";
        std::cin >> x;
        switch (x) {
            case 0:
                std::cout << "Exiting";
                break;

            case 1:
                std::cout << "Enter number of Students enrolled in the B.Tech programme ( <10 ):: ";
                std::cin >> n;
                std::cout << "Enter data of " << n << " student(s)";
                S = B;
                for (int i = 0; i < n; ++i) {
                    std::cout << "Student #" << i + 1 << '\n';
                    B[i].getval();
                }
                S->sort(n);
                std::cout << "The details of students sorted according to Marks :: \n";
                for (int i = n - 1; i >= 0; --i) {
                    B[i].display();
                }
                break;
            case 2:
                std::cout << "Enter number of Students enrolled in the M.Tech programme ( <10 ):: ";
                std::cin >> n;
                std::cout << "Enter data of " << n << " student(s)\n";
                S = M;
                for (int i = 0; i < n; ++i) {
                    std::cout << "Student #" << i + 1 << '\n';
                    M[i].getval();
                }
                S->sort(n);
                std::cout << "The details of students sorted according to Marks :: \n";
                for (int i = n - 1; i >= 0; --i) {
                    M[i].display();
                }
                break;
            default:
                std::cout << "Invalid entry!";
        }
    }
    return 0;
}

