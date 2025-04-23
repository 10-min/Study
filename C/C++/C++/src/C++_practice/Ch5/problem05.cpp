#include <iostream>
#include <string>
int main() {
    using namespace std;
    string months[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    
    int monthlyBooks[12];
    int sum = 0;
    cout << "Enter the monthly sales for 1 year\n";
    for (int i = 0; i < 12; i++) {
        cout << months[i] << ": ";
        cin >> monthlyBooks[i];
        sum += monthlyBooks[i];
    }

    cout << "Total sales for 1 year: " << sum << endl;
    return 0;
}