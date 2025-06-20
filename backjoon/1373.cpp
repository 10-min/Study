#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
    using namespace std;

    string str;

    cin >> str;
    vector<int> st;
    
    while (str.length() % 3 != 0) {
        str = "0" + str;


    }
    int i = 0;
    
    string result = "";
    int sum = 0;

    for (int i = 0; i < str.length(); i+=3) {
        sum = (str[i] - '0') * 4 + (str[i+1] - '0') * 2 + (str[i+2] - '0') * 1;
        result += to_string(sum);
    }
    
    cout << result << '\n';
    return 0;
}