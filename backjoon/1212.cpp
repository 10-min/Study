#include <iostream>
#include <string>

int main() {
    using namespace std;
    
    string oct[] = {"000", "001", "010", "011", "100", "101", "110", "111"};

    string input;
    cin >> input;

    string result;

    for (int i = 0; i < input.length(); i++) {
        result += oct[input[i] - '0'];
    }

    while (result.length() > 1 && result[0] == '0') {
        result = result.substr(1, result.length() - 1);
    }

    cout << result << endl;

    return 0;
}