#include <iostream>
#include <cctype>
#include <array>
int main() {
    using namespace std;

    const int Size = 10;
    array<double, Size>  donations;
    double sum = 0;
    cout << "Enter " << Size << " donations:\n";
    for (int i = 0; i < Size; i++) {
        if (!(cin >> donations[i])) {
            cout << "Please enter double type!!";
            return -1;
        }
        sum += donations[i];
    }
    double average = sum / Size;
    int count = 0;
    for (double donation : donations) {
        if (average < donation) count++;
    }

    cout << "Average of donations: " << average << endl;
    cout << "The number of donations larger than average: " << count << endl;
    return 0;
}