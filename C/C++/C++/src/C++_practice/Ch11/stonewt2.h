#ifndef STONEWT2_H_
#define STONEWT2_H_

#include <iostream>

class Stonewt
{
private:
    enum
    {
        Lbs_per_stn = 14
    };
    enum Mode {
        STONE,
        INT_POUND,
        DB_POUND 
    };
    int stone;
    double pds_left;
    double pounds;
    Mode mode;

public:
    Stonewt(double lbs, Mode mode = STONE);
    Stonewt(int stn, double lbs, Mode mode = STONE);
    Stonewt();
    ~Stonewt();
    void st_mode();
    void int_pd_mode();
    void db_pd_mode();

    operator int() const;
    operator double() const;
    Stonewt operator+(const Stonewt & s) const;
    Stonewt operator-(const Stonewt & s) const;
    Stonewt operator*(double n);
    friend Stonewt operator*(double n, const Stonewt & st);
    friend std::ostream & operator<<(std::ostream & os, const Stonewt & st);
};
#endif