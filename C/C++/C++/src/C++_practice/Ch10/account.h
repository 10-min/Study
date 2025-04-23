#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
class Account {
public:
    Account(const std::string name = "", const std::string account_number = "",
    const double balance = 0) {
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
    };

    void describe_account();
    void deposit(double money);
    void withdraw(double money);
private:
    std::string name;
    std::string account_number;
    double balance;
};

#endif
