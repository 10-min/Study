#include<iostream>
#include<string>

using namespace std;

void crazyCaps(string& str) {
    int length = str.length();
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            if (isupper(str[i])) {
                str[i] =  tolower(str[i]);
                
            } 
        } else {
            if (islower(str[i])) {
                str[i] = toupper(str[i]);
            }
        }
        
    }
}

int main() {

    string str = "Hey!! THERE";

    crazyCaps(str);

    cout << str;
}