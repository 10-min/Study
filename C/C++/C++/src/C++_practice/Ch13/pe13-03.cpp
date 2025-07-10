#include <iostream>
#include <string>
#include "dmaabc.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    baseDMA * dma[4];

    std::string label;
    int rating;
    for (int i = 0; i < 4; i++) {
        cout << "상표를 입력하세요: ";
        cin >> label;
        cout << "등급을 입력하세요: ";
        cin >> rating;
        
        char type;
        cout << "타입을 선택하세요(lacksDMA: 1, hasDMA: 2) : ";

        while (cin >> type && type != '1' && type != '2') {
            cout << "1 또는 2만 선택 가능합니다: ";
        }

        if (type == '1') {
            std::string color;
            cout << "색상을 입력하세요: ";
            cin >> color;

            dma[i] = new lacksDMA(color.c_str(), label.c_str(), rating);
        } else if (type == '2') {
            std::string style;
            cout << "스타일을 입력하세요: ";
            cin >> style;
            dma[i] = new hasDMA(style.c_str(), label.c_str(), rating);
        }
        while (cin.get() != '\n')
            continue;
    }

    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        dma[i]->View();
        cout << endl;
    }

    for (int i = 0; i < 4; i++)
        delete dma[i];
}