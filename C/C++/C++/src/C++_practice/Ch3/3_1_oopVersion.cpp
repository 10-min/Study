#include <iostream>

class meterAndCentimeter {
    private:
    int meter;
    int centimeter;
    
    public:
    meterAndCentimeter(int meter, int centimeter) {
        this->meter = meter;
        this->centimeter = centimeter;
    }

    int getMeter() {
        return meter;
    }

    int getCentimter() {
        return centimeter;
    }
};

class cmToMeterAndCentimeterChanger {
    private:
    const int CmPerMeter {100};

    public:
    meterAndCentimeter changeToMeterAndCentimeter(int centimeter) {
        return meterAndCentimeter(centimeter / CmPerMeter, centimeter % CmPerMeter);
    }
};

int main() {
    using namespace std;
    
    int height;
    cout << "Enter your height in centimeter: ___\b\b\b";
    cin >> height;

    cmToMeterAndCentimeterChanger heightChanger;
    meterAndCentimeter heightInMeterAndCentimeter = heightChanger.changeToMeterAndCentimeter(height);

    int meter {heightInMeterAndCentimeter.getMeter()}, centimeter {heightInMeterAndCentimeter.getCentimter()};

    cout << "Your height " << height << "cm "
    << "is:\n";
    cout << meter << "m " << centimeter << "cm.\n";
    return 0;
}