#ifndef MOVE_H
#define MOVE_H

class Move
{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0);
    void showmove() const;
    Move add(Move & m) const;
    void reset(double a = 0, double b = 0);
};

#endif