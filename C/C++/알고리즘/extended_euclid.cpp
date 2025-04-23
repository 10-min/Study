#include <iostream>


using namespace std;
void extended_euclidean(long long a, long long b, long long &d, long long &x, long long &y) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
    } else {
        long long x1, y1;
        extended_euclidean(b, a % b, d, x1, y1);
        x = y1;
        y = x1 - (long(a / b) * y1);

    }
}
int main() 
{
    long long N, A, d, x, y;
    cin >> N;
    cin >> A;
    
    long long a_inverse, m_inverse;
    a_inverse = N - A;
    extended_euclidean(A, N, d, x, y);
    if (x < 0)
        x += N;
    if (d != 1)
        m_inverse = -1;
    else
        m_inverse = x;
    
    cout << a_inverse << ' ' << m_inverse;

    return 0;
}