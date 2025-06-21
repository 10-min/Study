#ifndef PLORG_H
#define PLORG_H

class Plorg {
private:
    static const int MAX = 19;
    char name[MAX];
    int CI;
public:
    Plorg(const char * name = "Plorga", int CI = 50);
    void setCI(int CI);
    void showplorg() const;
};

#endif