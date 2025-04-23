#include<iostream>
#include<string>

using namespace std;

string addCommas(string num) {
    int length = num.length();

    int n_comma = (length-1) / 3;
    int mod = length % 3;

    int comma_index = mod;
    if (!comma_index) comma_index = 3;

    for (int i = 0; i < n_comma; i++) {
        num.insert(comma_index, ",");
        comma_index += 4;
    }
    return num;
}

int main() {
    string str = "888888888888888";
    cout << addCommas(str);
    
    return 0;
}