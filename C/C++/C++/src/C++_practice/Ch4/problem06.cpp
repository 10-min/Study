#include <iostream>

struct CandyBar
{
    char brand[20];
    double weight;
    int kcal;

};

int main() {
    using namespace std;
    CandyBar snack[2] = {
        {"Mocha Munch", 2.3, 350},
        {"Mozzi", 3.2, 300}
    };

    cout << "Snack1 Brand: " << snack[0].brand << endl;
    cout << "Snack1 Weight: " << snack[0].weight << endl;
    cout << "Snack1 kcal: " << snack[0].kcal << endl;
    cout << endl;
    cout << "Snack2 Brand: " << snack[1].brand << endl;
    cout << "Snack2 Weight: " << snack[1].weight << endl;
    cout << "Snack2 kcal: " << snack[1].kcal << endl;

    return 0;
}