#include <iostream>
#include "stonewt2.h"

int main() {
    using std::cout;
    using std::endl;
    Stonewt poppins(9, 2.8);
    Stonewt st1(5, 3.7);
    Stonewt st2(50);
    
    cout << "poppin\n";
    cout << poppins << endl; 
    cout << "st1\n";
    cout << st1 << endl;
    cout << "st2\n";
    cout << st2 << endl;

    cout << "st1 + st2 = " << st1 + st2 << endl;
    st1.db_pd_mode();
    cout << "st1 * 3.0 = " << st1 * 3.0 << endl;
    
    return 0;
}