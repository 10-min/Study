#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> parseredInts;
    
    stringstream ss(str);
    int value;
    while (ss >> value) {
        parseredInts.push_back(value);
        char ch;
        ss >> ch;
    }
    return parseredInts;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
