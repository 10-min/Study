#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;

    string input;

    vector<string> str_tail;

    cin >> input;
    
    string temp = "";
    for (int i = input.length() - 1; i >= 0; i--) {
        temp = input[i] + temp;
        str_tail.push_back(temp);
    }

    sort(str_tail.begin(), str_tail.end());

    for (string str : str_tail) {
        cout << str << endl;
    }

    return 0;
}