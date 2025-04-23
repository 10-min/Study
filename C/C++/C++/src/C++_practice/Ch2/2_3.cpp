#include<iostream>

void printThreeBlindMice();
void printSeeHowTheyRun();

int main() {
    printThreeBlindMice();
    printThreeBlindMice();
    printSeeHowTheyRun();
    printSeeHowTheyRun();
}

void printThreeBlindMice() {
    std::cout << "Three blind mice" << std::endl; 
}
void printSeeHowTheyRun() {
    std::cout << "See How They Run" << std::endl; 
}