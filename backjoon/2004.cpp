#include <iostream>

int the_number_of_something(long long n, int something) {
    long long count = 0;
    
    for (long long i = something; i <= n; i*= something) {
        count += n / i;
    }
    return count;
}

int main() {
    using namespace std;

    long long n, m;

    cin >> n >> m;

    long long two = the_number_of_something(n, 2) - (the_number_of_something(n - m, 2) + the_number_of_something(m, 2));
    long long five = the_number_of_something(n, 5) - (the_number_of_something(n - m, 5) + the_number_of_something(m, 5));
    int count;
    
    cout << min(five, two) << endl;

    return 0;
}