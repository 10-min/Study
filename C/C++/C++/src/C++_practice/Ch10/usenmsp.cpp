#include "namesp.h"

int main()
{
    using namespace SALES;
    double ar[4] = {100.0, 200.0, 300.0, 400.0};
    Sales s[2] = {Sales(ar, 4), Sales()};

    for (int i = 0; i < 2; i++)
    {
        s[i].showSales();
    }
    return 0;
}