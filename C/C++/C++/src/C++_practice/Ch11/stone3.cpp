#include "stonewt3.h"
#include <iostream>
#include <limits>

int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    
    Stonewt stones[6] = {Stonewt(100), Stonewt(180), Stonewt(50)};
    Stonewt base(11, 0);

    Stonewt max = Stonewt(0);
    Stonewt min = Stonewt(__DBL_MAX__);
    int count = 0;

    for (int i =0 ; i < 3; i++) {
        int stone;
        double pds_left;
        cout << "Stone: ";
        cin >>  stone;
        cout << "Pounds: ";
        cin >> pds_left;
        stones[i+3] = Stonewt(stone, pds_left);
    }

    for (int i = 0; i < 6; i++) {
        if (stones[i] >= base) {
            count++;
        }
        if (max < stones[i]) {
            max = stones[i];
        }
        if (min > stones[i]) {
            min = stones[i];
        }
    }

    cout << "최대 원소: ";
    max.show_stn();
    cout << "최소 원소: ";
    min.show_stn();
    cout << "11스톤보다 크거나 같은 원소 개수: " << count << endl;
    return 0;
}