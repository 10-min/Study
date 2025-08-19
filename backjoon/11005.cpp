#include <iostream>
#include <string>

char intToChar(int i) {
    if (i < 10) return '0' + i;
    else return 'A' + (i - 10);
}

int main() {
    long long N;
    int B;
    std::cin >> N >> B;
    std::string result = "";

    while (true) {
        if (N / B == 0)
        {
            result = intToChar(N) + result;
            break;
        }
        result = intToChar(N % B) + result;
        N /= B;
    }
    std::cout << result << std::endl;

    return 0;
}
