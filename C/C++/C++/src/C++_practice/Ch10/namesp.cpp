#include "namesp.h"
#include <iostream>
#include <algorithm>
#include <climits>

namespace SALES
{
    const int Sales::QUARTERS;
}

SALES::Sales::Sales(const double ar[], int n)
{
    int size = std::min(n, QUARTERS);
    double sum = 0;
    double min = 1000000;
    double max = 0;
    for (int i = 0; i < QUARTERS; i++)
    {
        if (i < size)
        {
            double sale = ar[i];

            sales[i] = sale;
            if (min > sale)
            {
                min = sale;
            }
            if (max < sale)
            {
                max = sale;
            }
            sum += sale;
        }
        else
        {
            sales[i] = 0;
        }
    }
    average = sum / size;
    this->min = min;
    this->max = max;
}

SALES::Sales::Sales()
{
    using namespace std;

    double sum = 0;
    double max = 0;
    double min = 1000000;
    for (int i = 0; i < QUARTERS; i++)
    {
        cout << "Quarters " << i + 1 << endl;
        cout << "sale: ";
        double value;
        cin >> value;
        if (min > value)
        {
            min = value;
        }
        if (max < value)
        {
            max = value;
        }
        sales[i] = value;
        sum += value;
    }

    average = sum / QUARTERS;
    this->min = min;
    this->max = max;
}

void SALES::Sales::showSales()
{
    using namespace std;
    cout << "Show Sales" << endl;
    for (int i = 0; i < QUARTERS; i++)
    {
        cout << "Quarters " << i + 1 << endl;
        cout << "sale: " << sales[i] << endl;
    }
    cout << "Average: " << average << endl;
    cout << "Max: " << max << endl;
    cout << "Min :" << min << endl;
}