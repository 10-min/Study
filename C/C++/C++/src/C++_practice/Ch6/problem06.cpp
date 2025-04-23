#include <iostream>
#include <string>
#include <set>
struct donator {
    std::string name;
    double donation;
};

int main() {
    using namespace std;

    cout << "Society for the Preservation of Rightfull Influence\n";
    cout << "How many people do donation? : ";
    int numOfDonator;
    cin >> numOfDonator;
    cin.ignore();

    donator* donatorArr = new donator[numOfDonator];

    set<int> highDonatorIndex;
    set<int> lowDonatorIndex;
    for (int i = 0; i < numOfDonator; i++) {
        cout << "Donator " << i + 1 << endl;
        cout << "Name: ";
        getline(cin, donatorArr[i].name);
        cout << "Donation: ";
        cin >> donatorArr[i].donation;
        cin.ignore();
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
    return 0;
}   