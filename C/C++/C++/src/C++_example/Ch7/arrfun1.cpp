#include <iostream>
const int ArSize = 8;
int sum_arr(int arr[], int n);
int main() {
    using namespace std;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};

    int sum = sum_arr(cookies, ArSize);
    cout << "먹은 과자 수 합계: " << sum << "\n";
    return 0;
}

int sum_arr(int arr[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        int total = 0;

        for  (int i = 0; i < n; i++) 
            total = total + arr[i];
        return total;
    }
}