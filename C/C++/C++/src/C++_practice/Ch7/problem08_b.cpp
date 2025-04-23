#include <iostream>
#include <string>

const int Seasons = 4;
const char *Sname[] = 
    {"Spring", "Summer", "Fall", "Winter"};
    
struct array {
    double expenses[Seasons];
};

void fill(array *pa);
void show(array da);

int main() {
    array expenses;
    fill(&expenses);
    show(expenses);
    return 0;
}

void fill(array *pa) {
    using namespace std;
    for (int i = 0; i < Seasons; i++) {
        cout << Sname[i] << "에 소요되는 비용: ";
        cin >> pa->expenses[i];
    }
}

void show(array da) {
    using namespace std;
    double total = 0.0;
    cout << "\n계절별 비용\n";
    for (int i = 0; i < Seasons; i++) {
        cout << Sname[i] << " : $" << da.expenses[i] << endl;
        total += da.expenses[i];
    }
    cout << "총 비용 : $" << total << endl;
}