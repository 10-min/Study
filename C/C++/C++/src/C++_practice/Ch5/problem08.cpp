#include <iostream>
#include <cstring>
int main() {
    using namespace std;
    
    cout << "영어 단어들을 입력하십시오 (끝내려면 done을 입력):\n";

    int count = 0;
    char str[20];
    cin >> str;
    while (strcmp(str, "done") != 0) {
        count++;
        cin >> str;
    }
    cout << "총 " << count << " 단어가 입력되었습니다.\n";
    return 0;
}