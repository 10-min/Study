#include <iostream>
#include "stock20.h"

const int STKS = 4;
int main() {
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Oblisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "보유 주식 리스트:\n";
    int st;
    for (st = 0; st < STKS; st++) {
        stocks[st].show();
    }

    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);

    std::cout << "\n최고 가치의 주식:\n";
    top->show();
    return 0;
}