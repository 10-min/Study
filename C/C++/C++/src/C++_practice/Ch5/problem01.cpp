#include <iostream>
int main() {
    using namespace std;

    int n1, n2;
    
    cout << "Enter the two integers orders by acending with space : ";
    cin >> n1 >> n2;

    int sum = 0;

    for (int i = n1; i <= n2; i++) {
        sum += i;
    }

    cout << "Sum of integers between " << n1 << " and " << n2
        << " is " << sum << ".\n";
    
    return 0;
}