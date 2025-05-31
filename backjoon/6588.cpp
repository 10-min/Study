#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> temp(1000001, true);

    temp[0] = 0;
    temp[1] = 0;

    for (int i = 2; i * i < temp.size(); i++) {
        int mul = i * i;
        if (temp[i]) {
            while (mul < temp.size()) {
                temp[mul] = false;
                mul += i;
            }
        
        }
    }

    int n;
    
    while (cin >> n && n != 0) {
        bool found = false;
        for (int i = 3; i <= n / 2; i += 2) {
            if (temp[i]) {
                if (temp[n - i]) {
                    found = true;
                    cout << n << " = " << i << " + " << n-i << '\n';
                    break;
                }
            }
        }

        if (!found) {
            cout << "Goldbach's conjecture is wrong\n";
        }

    }

    return 0;
}