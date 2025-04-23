#include <iostream>

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void printBoxMember(box b) {
    using namespace std;
    cout << "Maker: " << b.maker << endl;
    cout << "Height: " << b.height << endl;
    cout << "Width: " << b.width << endl;
    cout << "Length: " << b.length << endl;
    cout << "Volume: " << b.volume << endl;
}
void setBoxVolume(box *b) {
    b->volume = b->height * b->width * b->length;
}

int main() {
    box b = {"Ace", 30, 20, 50};
    setBoxVolume(&b);
    printBoxMember(b);
    return 0;
}