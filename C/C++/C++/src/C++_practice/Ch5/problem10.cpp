#include <iostream>
int main() {
    using namespace std;

    cout << "출력할 행 수를 입력하십시오: ";
    int numberOfRow;
    cin >> numberOfRow;

    for (int numberOfStar = 1; numberOfStar <= numberOfRow; numberOfStar++) {
        for (int i = 0; i < numberOfRow; i++) {
            if (i < numberOfRow - numberOfStar) {
                cout << '.';
            } else {
                cout << '*';
            }
        }
        cout << endl;
    }
    return 0;
}