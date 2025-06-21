#include "stack.h"
#include <iostream>

int main() {

    customer customers[3] = {{"A", 100}, {"B", 20}, {"C", 50}};

    Stack st;

    for (int i = 0; i < 3; i++) {
        st.push(customers[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        st.pop();
    }

    return 0;
}