#ifndef GOLF_H
#define GOLF_H

class Golf 
{
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;
public:
    Golf();
    Golf(const char *name, int hc);

    int setgolf();

    void sethandicap(int hc);

    void showgolf();
};



#endif