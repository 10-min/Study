#include <iostream>
#include <string>

int main() {
    using namespace std;

    string A, B, C, D;

    cin >> A >> B >> C >> D;

    cout << stoll(A+B) + stoll(C+D) << endl;

    return 0;
}