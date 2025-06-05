#include "header_4.h"
#include <iostream>
#include <algorithm>
#include <climits>

void SALES::setSales(SALES::Sales & s, const double ar[], int n) {
    int size = std::min(n, SALES::QUARTERS);
    double sum = 0;
    double min = 1000000;
    double max = 0;
    for (int i = 0; i < SALES::QUARTERS; i++) {
        if (i < size) {
            double sale = ar[i];
        
            s.sales[i] = sale;
            if (min > sale) {
                min = sale;
            }
            if (max < sale) {
                max = sale;
            }
            sum += sale;
        } else {
            s.sales[i] = 0;
        }
        
    }
    s.average = sum / size;
    s.min = min;
    s.max = max;
}

void SALES::setSales(SALES::Sales & s) {
    using namespace std;
    
    double sum = 0;
    double max = 0;
    double min = 1000000;
    for (int i = 0; i < SALES::QUARTERS; i++) {
        cout << "Quarters " << i + 1 << endl;
        cout << "sale: ";
        double value;
        cin >> value;
        if (min > value) {
            min = value;
        }
        if (max < value) {
            max = value;
        }
        s.sales[i] = value;
        sum += value;
    }

    s.average = sum / SALES::QUARTERS;
    s.min = min;
    s.max = max;
}

void SALES::showSales(const Sales & s) {
    using namespace std;
    cout << "Show Sales" << endl;
    for (int i = 0; i < SALES::QUARTERS; i++) {
        cout << "Quarters " << i + 1 << endl;
        cout << "sale: " << s.sales[i] << endl;
    }
    cout << "Average: " << s.average << endl;
    cout << "Max: " << s.max << endl;
    cout << "Min :" << s.min << endl;
}