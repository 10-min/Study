#include "header_4.h"

int main() {
    using namespace SALES;
    Sales s[2];
    double ar[4] = {100.0, 200.0, 300.0, 400.0};
    setSales(s[0], ar, 4);
    setSales(s[1]);

    for (int i = 0; i < 2; i++) {
        showSales(s[i]);
    }
    return 0;
}