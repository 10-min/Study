#ifndef LIST_H_
#define LIST_H_

#include "stack.h"

typedef customer Item;

class List
{
private:
    enum
    {
        MAX = 10
    };
    Item items[MAX];
    int length;

public:
    List();
    bool isempty() const;
    bool isfull() const;

    bool insert(const Item &item);
    void visit(void (*pf)(Item &));
};
#endif