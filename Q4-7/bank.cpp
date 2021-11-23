//
// Created by Rohit T P on 02-11-2021.
//

#include <iostream>
#include <conio.h>

class Account {
private:
    std::string name;
    long int number{};
    float balance{};
    std::string type;

public:
    void init() {
        std::cout << "Enter name :";
        std::cin >> name;

        std::cout << "Enter Account Number :";
        std::cin >> number;

        std::cout << "Enter Balance :";
        std::cin >> balance;

        std::cout << "Enter Account Type :";
        std::cin >> type;
    }

    void deposit() {
        std::cout << "Enter amount deposit" << std::endl;
        float amount;
        std::cin >> amount;

        this->balance += amount;
    }

    int withdraw() {
        std::cout << "Enter amount to withdraw. ( Current balance: " << this->balance << " )" << std::endl;
        float amount;

        std::cin >> amount;

        if (this->balance - amount < 500)
            return std::cout << "In sufficient balance", 1;

        this->balance -= amount;
        return 0;
    }

    void print() {
        std::cout << "Account Holder\t" << name << std::endl << "Balance\t" << balance << std::endl;
    }

};

void highlight_option(int index, char options[][16], int items) {
    std::cout << "\033[2J\033[1;1H" << std::flush;
    std::cout << "Press Enter to select any other key to exit." << std::endl;

    for (int i = 0; i < items; i++)
        if (i == index)
            std::cout << "(#) " << options[i] << std::endl;
        else
            std::cout << "( ) " << options[i] << std::endl;
}

int handle_key() {
    unsigned char ch = _getch();

    if (ch == 224)
        return _getch() == 72 ? -1 : 1;

    return ch == 13 ? 0 : 2;
}

int get_choice(char menu_options[][16], int items = 4) {
    int menu_index = 0;

    while (true) {
        highlight_option(menu_index, menu_options, items);
        int action = handle_key();

        if (!action)
            break;
        if (action > 1)
            return items + 1;

        menu_index = (menu_index + action) % items;
    }

    return menu_index;
}

int main() {
    char menu_options[][16] = {
            "Create Account",
            "Show My Details",
            "Deposit",
            "Withdraw"
    };

    int items = 4;
    int choice = 0;

    Account account;

    while (choice < items) {
        choice = get_choice(menu_options, items);
        switch (choice) {
            case 0:
                account.init();
                break;
            case 1:
                account.print();
            case 3:
                account.deposit();
            case 4:
                account.withdraw();
            default:
                return 0;
        }
    }

    return 0;
}
