#include<iostream>
#include<string>

using namespace std;

char shift_char(char ch, int n) {
    n%=26;

    if (ch >= 'a' && ch <= 'z') {
        ch = 'A' + ch - 'a';
    }

    if (ch >= 'A' && ch <= 'Z') {
        int offset = ch - 'A' + n;
        if (offset < 0) {
            offset = 26 + offset;
        }
        ch = 'A' + offset%26;
    }

    return ch;
}
void caesarCipher(string& str, int n) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = shift_char(str[i], n);
    }
}

int main() {
    string str;
    int n;
    
    cout << "Your message? ";
    getline(cin, str);
    cout << "Encoding key? ";
    cin >> n;
    caesarCipher(str, n);

    cout << str;
    return 0;
}