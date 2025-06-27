#ifndef STONEWT2_H_
#define STONEWT2_H_

class Stonewt
{
private:
    enum
    {
        Lbs_per_stn = 14
    };
    int stone;
    double pds_left;
    double pounds;

public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;

    operator int() const;
    operator double() const;
    Stonewt operator*(double n);
    friend Stonewt operator*(double n, const Stonewt & st);
};
#endif