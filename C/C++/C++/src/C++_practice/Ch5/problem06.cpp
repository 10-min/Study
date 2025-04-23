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
    
    int monthlyBooks[3][12];
    int sum = 0;
    int total = 0;

    for (int i = 0; i < 3; i++) {
        cout << "Enter the monthly sales in " << i+1 << "th " << "year\n";
        sum = 0;
        for (int j = 0; j < 12; j++) {
            cout << months[j] << ": ";
            cin >> monthlyBooks[i][j];
            sum += monthlyBooks[i][j];
        }
        cout << "Sales in " << i+1 << "th " << "year: " << sum << endl;
        total += sum;
    }
    
    cout << "Total sales for 3 year: " << total << endl;
    return 0;
}