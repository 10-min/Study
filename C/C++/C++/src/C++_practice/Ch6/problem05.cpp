#include <iostream>

int main() {
    using namespace std;
    double tvarp, temp;
    int standard[] = {5000, 10000, 20000};
    double rate[] = {0, 0.1, 0.15};

    do {
        cout << "Enter your revenue in tvarp: ";
        cin >> tvarp;
        temp = tvarp;
        double incomeTax = 0;
        if (cin.fail() || tvarp < 0) {
            cout << "Wrong Type!!\n";
            break;  
        }
        bool end = false;
        for (int i = 0; i < 3; i++) {
            
            if (temp <= standard[i]) {
                end = true;
                incomeTax += temp * rate[i];
            } else {
                incomeTax += standard[i] *  rate[i];
                temp -= standard[i];
            }
            if (end) break;
        }
        if (!end) {
            incomeTax += temp * 0.2;
        }

        cout << "Total Income Tax: " << incomeTax << endl;
    } while (1); 
    
    return 0;
}