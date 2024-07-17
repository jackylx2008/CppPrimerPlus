#include "./BankAccount.h"

int main(int argc, char *argv[]) {
    BankAccount people1("liuxin", "123456", 10000);
    people1.show();
    people1.deposit(100);
    people1.show();
    people1.withdraw(500);
    people1.show();
    people1.withdraw(500000);
    people1.show();
    return 0;
}
