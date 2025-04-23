#include <iostream>
int main() {
    using namespace std;
    cout << "다음 선택 사항 중에서 하나를 선택하십시오. (끝내려면 q)\n";
    cout << "c) camera \t p) pianist\n";
    cout << "t) tree \t g) game\n";
    char ch;
    cin >> ch;
    while (ch != 'q') {
        switch (ch) {
            case 'c':
                cout << "카메라는 DSLR.\n";
                break;
            case 'p':
                cout << "피아니스트는 창을 잘 피아니스트?\n";
                break;
            case 't':
                cout << "단풍나무는 잎이 별처럼 생겼습니다.\n";
                break;
            case 'g':
                cout << "할 Game이 없네\n";
                break;
            default:
                cout << "c, p, t, g 중에서 하나를 선택하십시오. (끝내려면 q) : ";
        }
        cin >> ch;
    }
    return 0;
}