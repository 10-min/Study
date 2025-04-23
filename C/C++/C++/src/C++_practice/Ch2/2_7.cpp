#include<iostream>

void printTime(int, int);

int main() {
    using namespace std;
    cout << "Enter Hour : ";
    
    int hour;
    cin >> hour;

    cout << "Enter Minute : ";
    
    int minute;
    cin >> minute;

    printTime(hour, minute);

    return 0;
    
}

void printTime(int hour, int minute) {
    using namespace std;

    cout << "Time : " << hour << ":" << minute << endl;
}
    
