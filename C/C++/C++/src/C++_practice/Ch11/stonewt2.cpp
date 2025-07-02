#include <iostream>
using std::cout;
#include "stonewt2.h"

Stonewt::Stonewt(double lbs, Mode mode)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    this->mode = mode;
}

Stonewt::Stonewt(int stn, double lbs, Mode mode)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    this->mode = mode;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
    mode = STONE;
}

Stonewt::~Stonewt() {}

void Stonewt::st_mode() {
    mode = STONE;
}

void Stonewt::int_pd_mode() {
    mode = INT_POUND;
}

void Stonewt::db_pd_mode() {
    mode = DB_POUND;
}

Stonewt::operator int() const
{
    return int(pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}

Stonewt Stonewt::operator+(const Stonewt & st) const {
    double sum;
    sum = pounds + st.pounds;
    return Stonewt(sum);
}

Stonewt Stonewt::operator-(const Stonewt & st) const {
    double diff;
    diff = pounds - st.pounds;
    return Stonewt(diff);
}

Stonewt Stonewt::operator*(double n) {
    return Stonewt(pounds * n, mode);
}

Stonewt operator*(double n, const Stonewt & b) {
    return Stonewt(b.pounds * n, b.mode);
}

std::ostream & operator<<(std::ostream & os, const Stonewt & st) {
    if (st.mode == Stonewt::STONE) {
        os << st.stone << "스톤, " << st.pds_left << "파운드";
    } else if (st.mode == Stonewt::INT_POUND) {
        os << int(st.pounds) << "파운드";
    } else if (st.mode == Stonewt::DB_POUND) {
        os << double(st.pounds) << "파운드";
    }
    return os;
}