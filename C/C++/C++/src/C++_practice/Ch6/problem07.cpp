#include <iostream>
#include <cctype>
#include <string>
#include <set>

int main() {
    using namespace std;
    int cntStartVowel = 0;
    int cntStartConsonant = 0;
    int cntStartOther = 0;
    set<char> vowels = {'a', 'i', 'o', 'u', 'e'};

    cout << "단어들을 입력하시오 (끝내려면 q):\n";
    string word;
    while (1) {
        cin >> word;
        char firstChar = tolower(word[0]);
        if (word == "q") break;
        else if (isalpha(firstChar)) {
            if (vowels.find(firstChar) != vowels.end()) {
                cntStartVowel++;
            } else {
                cntStartConsonant++;
            }
        } else {
            cntStartOther++;
        }
    }
    cout << "모음으로 시작하는 단어 수: " << cntStartVowel << endl;
    cout << "자음으로 시작하는 단어 수: " << cntStartConsonant << endl;
    cout << "기타: " << cntStartOther << endl;
    return 0;
}