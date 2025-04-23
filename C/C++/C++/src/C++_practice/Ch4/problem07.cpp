#include <iostream>

struct Pizza {
    char company[20];
    double radius;
    int weight;
};
int main() {
    using namespace std;

    Pizza pizza;

    cout << "Enter pizza company: ";
    cin.getline(pizza.company, 20);
    cout << "Enter pizza radius: ";
    cin >> pizza.radius;
    cout << "Enter pizza weight: ";
    cin >> pizza.weight;

    cout << "Pizza" << endl;
    cout << "==========" << endl;
    cout << "Company: " << pizza.company << endl;
    cout << "Radius: " << pizza.radius << endl;
    cout << "Weight: " << pizza.weight << endl;

    return 0;
}