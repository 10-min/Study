#include <iostream>
#include <cstring>
#include "stock3.h"

Stock::Stock() {
    company = new char[8];
    strcpy(company, "no name");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, long n, double pr) {
    int len = strlen(co);
    company = new char[len + 1];
    strcpy(company, co);

    if (n < 0) {
        std::cout << "주식 수는 음수가 될 수 없으므로, "
                    << company << " shares를 0으로 설정합니다.\n";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

Stock::~Stock() {
    delete [] company;
}

void Stock::buy(long num, double price) {
    if (num < 0) {
        std::cout << "매입 주식 수는 음수가 될 수 없으므로, "
                    << "거래가 취소되었습니다.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    using std::cout;
    if (num < 0) {
        cout << "보유 주식보다 많은 주식을 매도할 수 없으므로, "
                << "거래가 취소되었습니다.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

std::ostream & operator<<(std::ostream & os, const Stock & s) {
    using std::cout;
    using std::ios_base;

    ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);

    os << "회사명: " << s.company
            << "주식 수: " << s.shares << '\n';
    os << "주가: $" << s.share_val << '\n';

    os.precision(2);
    os << " 주식 총 가치: $" << s.total_val << '\n';
    
    return os;
}

const Stock & Stock::topval(const Stock & s) const {
    if (s.total_val > total_val)
        return s;
    else 
        return *this;
}