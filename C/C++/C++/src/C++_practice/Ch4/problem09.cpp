#include <iostream>

struct CandyBar
{
    char brand[20];
    double weight;
    int kcal;

};

int main() {
    using namespace std;
    CandyBar * snack = new CandyBar[3];
    snack[0] = {"Mocha Munch", 2.3, 350};
    snack[1] = {"Mozzi", 2.0, 300};
    snack[2] = {"ROS", 5.2, 620};

    cout << "Snack1 Brand: " << snack[0].brand << endl;
    cout << "Snack1 Weight: " << snack[0].weight << endl;
    cout << "Snack1 kcal: " << snack[0].kcal << endl;
    cout << endl;
    cout << "Snack2 Brand: " << snack[1].brand << endl;
    cout << "Snack2 Weight: " << snack[1].weight << endl;
    cout << "Snack2 kcal: " << snack[1].kcal << endl;
    cout << endl;
    cout << "Snack3 Brand: " << snack[2].brand << endl;
    cout << "Snack3 Weight: " << snack[2].weight << endl;
    cout << "Snack3 kcal: " << snack[2].kcal << endl;

    return 0;
}