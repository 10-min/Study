#include <iostream>
#include <new>
#include <cstring>

const int BUF = 512;
char buffer[BUF];

struct chaff {
    char dross[20];
    int slag;
};

int main() {
    chaff* c = new (buffer) chaff[2];

    strcpy(c[0].dross, "gimo");
    c[0].slag = 1;
    strcpy(c[1].dross, "mojji");
    c[1].slag = 2;

    for (int i = 0; i < 2; i++) {
        std::cout << "c" << i << ": " 
                << "dross: " << c[i].dross << std::endl;
        std::cout << "slag: " << c[i].slag << std::endl;
    }
    return 0;
}