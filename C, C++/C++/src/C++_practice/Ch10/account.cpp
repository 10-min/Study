#include "account.h"
#include <iostream>

void Account::describe_account() {
    using namespace std;

    cout << "Name : " << Account::name << endl;
    cout << "Account number : " << Account::account_number << endl;
    cout << "Balance : " << Account::balance << endl;
}

void Account::deposit(double money) {
    if (money >= 0) {
        Account::balance += money;
    } else {
        std::cout << "Argument has to be positive" << std::endl;
    }
}

void Account::withdraw(double money) {
    if (Account::balance >= money) {
        Account::balance -= money;
    } else {
        std::cout << "Can't withdraw money more than balance" << std::endl;
    }
}