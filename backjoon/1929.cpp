#include <iostream>
#include <vector>

int main() {
    using namespace std;

    int m, n;

    cin >> m >> n;

    vector<int> arr(n + 1, 1);
    arr[0] = 0;
    arr[1] = 0;

    for (int i = 4; i < arr.size(); i += 2) {
        arr[i] = 0;
    }

    for (int i = 3; i < arr.size(); i++) {
        int mul = 2;
        while (i * mul < arr.size()) {
            arr[i * mul] = 0;
            mul++;
        }
    }

    for (int i = m; i < arr.size(); i++) {
        if (arr[i] == 1) {
            cout << i << endl;
        }
    }

}