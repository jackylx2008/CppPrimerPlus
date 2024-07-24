#include <iostream>

#include "./Brass.h"

const int CLIENTS = 2;

void TestBrass(void) {
    Brass null;
    Brass b1("liu", 123456, 5000);
    Brass cp_b1(b1);
    b1.ViewAccount();

    std::cout << "Deposit $1000" << std::endl;
    b1.Deposit(1000);
    b1.ViewAccount();

    std::cout << "Withdraw $2000" << std::endl;
    b1.Withdraw(2000);
    b1.ViewAccount();

    std::cout << "Withdraw $10000" << std::endl;
    b1.Withdraw(10000);
    b1.ViewAccount();

    std::cout << "null" << std::endl;
    null.ViewAccount();

    std::cout << "b1_cp" << std::endl;
    cp_b1.ViewAccount();
}

void TestBrassPlus(void) {
    BrassPlus null;
    BrassPlus bp1("liu", 123456, 5000, 1000, 1.1);
    Brass b1("xin", 654321, 500);
    BrassPlus bp2(100, 1.2, b1);
    BrassPlus cp_bp1(bp1);
    std::cout << "null" << std::endl;
    null.ViewAccount();

    std::cout << "cp_bp1" << std::endl;
    cp_bp1.ViewAccount();

    std::cout << "Deposit $1000" << std::endl;
    bp1.Deposit(1000);
    bp1.ViewAccount();

    std::cout << "Withdraw $2000" << std::endl;
    bp1.Withdraw(2000);
    bp1.ViewAccount();

    std::cout << "Withdraw $10000" << std::endl;
    bp1.Withdraw(10000);
    bp1.ViewAccount();

    std::cout << "Withdraw $4500" << std::endl;
    bp1.Withdraw(4500);
    bp1.ViewAccount();
}
int main(int argc, char *argv[]) {
    Brass *p_Brass[CLIENTS];
    for (int i = 0; i < CLIENTS; i++) {
        std::string name;
        std::cout << "Name :";
        getline(std::cin, name);
        int account = 0;
        std::cout << "Account Num :";
        std::cin >> account;
        double bal;
        std::cout << "Balance :$";
        std::cin >> bal;
        char type;
        std::cout << "1 for Brass;2 for BrassPlus" << std::endl;
        while (std::cin >> type && (type != '1' && type != '2')) {
            std::cout << "Enter either 1 or 2: ";
        }
        switch (type) {
            case '1':
                // std::cout << "Brass type" << std::endl;
                p_Brass[i] = new Brass(name, account, bal);
                break;
            case '2':
                // std::cout << "BrassPlus type" << std::endl;
                double loan = 0.0;
                double rate = 0.0;
                std::cout << "Loan :$";
                std::cin >> loan;
                std::cout << "Rate :";
                std::cin >> rate;
                p_Brass[i] = new BrassPlus(name, account, bal, loan, rate);
                break;
        }
        while (std::cin.get() != '\n') {
            continue;
        }
    }
    for (int i = 0; i < CLIENTS; i++) {
        p_Brass[i]->ViewAccount();
        std::cout << "-----------------" << std::endl;
    }
    for (int i = 0; i < CLIENTS; i++) {
        delete p_Brass[i];
    }
    return 0;
}
