#include<iostream>
#include<string>

using namespace std;

bool containsTwice(string str, char ch) {
    int index = 0;
    int found_index = str.find(ch, index);
    if (found_index == str.npos) return false;
    else {
        index = found_index + 1;
        found_index = str.find(ch, index);
        if (found_index == str.npos) {
            return false;
        } else return true;
    }
}

int main() {
    cout << containsTwice("hello", 'l');
    return 0;
}
