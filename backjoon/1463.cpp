#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> arr(N + 1);
    
    for (int i = 1; i < arr.size(); i++) {
        arr[i] = i - 1;
    }

    for (int i = 1; i < arr.size() - 1; i++) {
        if (arr[i + 1] > arr[i] + 1) arr[i + 1] = arr[i] + 1;
        if ((i * 2 <= N) && arr[i * 2] > arr[i] + 1) arr[i * 2] = arr[i] + 1;
        if ((i * 3 <= N) && arr[i * 3] > arr[i] + 1) arr[i * 3] = arr[i] + 1;
    }

    std::cout << arr[N] << std::endl;
    
    return 0;
}