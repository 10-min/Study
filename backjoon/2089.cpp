#include <iostream>
#include <string>

std::string calNegative(long long);

int main() {
    long long Q;

    // std::cin >> Q;
    for (long long i = 0; i < 10; i++) 
        std::cout << calNegative(i) << std::endl;
  
    return 0;
}

std::string calNegative(long long Q) {
    if (Q == 0) {
        return "0";
    }
    std::string result = "";
    while (Q != 1)
    {
        if (Q < 0 && (Q % 2 != 0))
        {
            result = "1" + result;
            Q = (Q / -2) + 1;
        }
        else
        {
            result = std::to_string(Q % -2) + result;
            Q /= -2;
        }   
    }
    result = "1" + result;

    return result;
}