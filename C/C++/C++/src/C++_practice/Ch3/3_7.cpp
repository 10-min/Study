#include <iostream>
int main() {
    using namespace std;

    const double GallonPerLiter {1/3.875};
    const double milesPer100km {62.14};

    double gasolineConsumptionInLiterPer100km;

    cout << "Enter the gasoline consumption in Europe style: ";
    cin >> gasolineConsumptionInLiterPer100km;

    double gasolineConsumptionInMpg = (1 / gasolineConsumptionInLiterPer100km) * (milesPer100km / GallonPerLiter);

    cout << "Your gasoline consumption in USA style is " << gasolineConsumptionInMpg << "mpg" << endl;

    return 0;
}