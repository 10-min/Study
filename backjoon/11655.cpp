#include <iostream>
#include <string>
#include <cctype>

char encrypt(char ch) {
    if (islower(ch)) {
        ch = 'a' + (ch - 'a' + 13) % 26;
    } else if (isupper(ch)) {
        ch = 'A' + (ch - 'A' + 13) % 26;
    }

    return ch;
}

int main() {
    using namespace std;

    string input;

    getline(cin, input);

    string result = "";

    for (int i = 0; i < input.length(); i++) {
        char each = input[i];
        if (isalpha(each)) {
            result += encrypt(each);
        } else {
            result += each;
        }
    }

    cout << result << endl;
    return 0;
}