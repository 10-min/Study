#include <iostream>
#include "stonewt1.h"

int main() {
    using std::cout;
    Stonewt poppins(9, 2.8);
    double p_wt = poppins;
    cout << "double형으로 변환 => ";
    cout << "Poppins; " << p_wt << "파운드\n";
    cout << "int형으로 변환 => ";
    cout << "Poppins: " << int (poppins) << "파운드\n";
    return 0;
}