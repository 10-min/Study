#include <iostream>
#include <string>

int main() {
    using namespace std;

    int alphabet[26] = {0};

    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        int index = input[i] - 'a';
        alphabet[index]++;
    }

    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << ' ';
    }

    cout << endl;

    return 0;
}