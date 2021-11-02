//
// Created by Rohit T P on 02-11-2021.
//

#include <iostream>

class Account {
private:
    std::string name;
    long int number{};
    float balance{};
    std::string type;

public:
    void init(std::string &newName, long int newNumber, float newBalance, std::string &newType) {
        name = newName;
        number = newNumber;
        balance = newBalance;
        type = newType;
    }

    void deposit(const float amount) {
        this->balance += amount;
    }

    bool withdraw(const float amount) {
        if (amount > this->balance)
            return false;

        this->balance -= amount;

        return true;
    }

    void print() {
        std::cout << "Account Holder\t" << name << std::endl << "Balance\t" << balance << std::endl;
    }

};

int main() {
    Account account;

    std::string name;
    long int number;
    float balance;
    std::string type;

    std::cout << "Enter name :";
    std::cin >> name;

    std::cout << "Enter Account Number :";
    std::cin >> number;

    std::cout << "Enter Balance :";
    std::cin >> balance;

    std::cout << "Enter Account Type :";
    std::cin >> type;

    account.init(name, number, balance, type);

    std::cout << "Enter Deposit :";
    std::cin >> balance;

    account.deposit(balance);

    std::cout << "Enter Withdraw :";
    std::cin >> balance;

    std::cout << (account.withdraw(balance) ? "Withdraw Success" : "Insufficient Balance") << std::endl;

    account.print();

    return 0;
}
