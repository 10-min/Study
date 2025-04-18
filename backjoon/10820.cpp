#include <iostream>
#include <cctype>
#include <string>

int main() {
    using namespace std;
    string input;
    while (getline(cin, input)) {
        int result[4] = {0};
        for (char ch : input) {
            if (islower(ch)) {
                result[0]++;
            } else if (isupper(ch)) {
                result[1]++;
            } else if (isdigit(ch)) {
                result[2]++;
            } else {
                result[3]++;
            }
        }
        for (int i = 0; i < 4; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}