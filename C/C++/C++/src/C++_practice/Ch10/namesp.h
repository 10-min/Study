#ifndef SALES_H
#define SALES_H

namespace SALES {
    class Sales
    {
    private:
        static const int QUARTERS = 4;
        double sales[QUARTERS];
        double average;
        double max;
        double min;

    public:
        Sales(const double ar[], int n);

        Sales();

        void showSales();
    };
}


#endif