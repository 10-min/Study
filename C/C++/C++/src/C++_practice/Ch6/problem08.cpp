#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

int main() {
    using namespace std;
    string filePath = "C:\\Users\\TM\\Desktop\\test.txt";

    std::ifstream file(filePath); // 파일 열기
    if (!file.is_open()) {
        std::cerr << "파일을 열 수 없습니다: " << filePath << std::endl;
        return 1;
    }
    int cntChar = 0;
    char ch;
    while (file.get(ch)) {
        cntChar++;
    }
    cout << "The number of char: " << cntChar << endl;
    file.close();
    return 0;
}
