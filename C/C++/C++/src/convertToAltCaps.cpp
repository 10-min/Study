#include<iostream>
#include<string>

using namespace std;

string convertToCaps(string str, int& caps) {
    for (int i = 0; i < str.length(); i++) {
        if (islower(str[i]) || isupper(str[i])) {
            if (!caps) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    str[i] = 'a' + str[i] - 'A';
                } 
            } else {
                if (str[i] >= 'a' && str[i] <= 'z')
                    str[i] = 'A' + str[i] - 'a';
            }

            caps = (caps + 1) % 2;
        }
        
    }
    return str;
}
string convertToAltCaps(string str) {
    int index = 0;
    int found_index = str.find(" ", index);
    int caps = 0;
    string tmp = "";

    while(found_index != str.npos) {
        string substr = str.substr(index, found_index - index);
        tmp += convertToCaps(substr, caps);
        tmp += " ";
        index = found_index;
        if (found_index < str.length()-1)
            index = found_index + 1;
        found_index = str.find(" ", index);
    }

    if (index != str.length() - 1) {
        tmp += convertToCaps(str.substr(index, str.length() - index), caps);
    }

    return tmp;
    
}
int main() {
    cout << convertToAltCaps("this  is   a     test");
    return 0;
}

