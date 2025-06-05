#include <iostream>
#include "golf.h"

int main() {
    golf arr[10];

    for (int i = 0; i < 10; i++) {
        if (!setgolf(arr[i])) {
            break;
        }
    }
    return 0;
}