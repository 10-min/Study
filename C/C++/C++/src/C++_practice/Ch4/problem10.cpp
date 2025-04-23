#include <iostream>
#include <array>

int main() {
    using namespace std;

    double time[3];
    int count = 0;
    for (int i = 0; i < 3; i++) {
        count++;
        cout << "Enter your 40m running result of try " << count << " in second: ";
        cin >> time[i];
    }

    for (int i = 0; i < count; i++) {
        cout << "Your 40m running result of try " << i+1 << ": " 
            << time[i] << " sec" << endl;
    }
    return 0;
}