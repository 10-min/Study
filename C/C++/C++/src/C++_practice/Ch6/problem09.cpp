#include <iostream>
#include <string>
#include <fstream>
#include <set>

struct donator {
    std::string name;
    double donation;
};

int main() {
    using namespace std;
    string filePath = "C://Users//TM//Desktop//donator.txt";
    ifstream  file(filePath);
    
    if (!file.is_open()) {
        std::cerr << "파일을 열 수 없습니다: " << filePath << std::endl;
        return 1;
    }

    cout << "Society for the Preservation of Rightfull Influence\n";
    int numOfDonator;
    file >> numOfDonator;
    file.ignore();
    donator* donatorArr = new donator[numOfDonator];

    set<int> highDonatorIndex;
    set<int> lowDonatorIndex;
    for (int i = 0; i < numOfDonator; i++) {
        getline(file, donatorArr[i].name);
        file >> donatorArr[i].donation;
        file.ignore();
        if (donatorArr[i].donation >= 10000) {
            highDonatorIndex.insert(i);
        } else {
            lowDonatorIndex.insert(i);
        }
    }
    cout << "고액 기부자\n";
    for (int index : highDonatorIndex) {
        cout << donatorArr[index].name << " " << donatorArr[index].donation << endl;
    }
    cout << "소액 기부자\n";
    for (int index : lowDonatorIndex) {
        cout << donatorArr[index].name << " " << donatorArr[index].donation << endl;
    }
}