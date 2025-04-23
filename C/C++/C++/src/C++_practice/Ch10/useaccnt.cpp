#include <iostream>
#include "account.h"

int main() {
    using namespace std;

    Account account = Account("taemin", "6531-1431-321", 100000);

    account.describe_account();

    account.deposit(1000);

    account.describe_account();

    account.withdraw(5000);

    account.describe_account();

    return 0;
}