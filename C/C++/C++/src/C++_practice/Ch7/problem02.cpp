#include <iostream>
#include <vector>

std::vector<double> getScore() {
    std::vector<double> scoreArr;
    std::cout << "Enter up to 10 scores\n";
    for (int i = 0; i < 10; i++) {
        double score;
        std::cin >> score;
        if (score < 0) break;
        scoreArr.push_back(score);
    }
    return scoreArr;
}

double getAverage(std::vector<double> scoreArr) {
    double sum = 0;
    int size = scoreArr.size();
    for (double score : scoreArr) {
        sum += score;
    }
    return sum / size;
}

void printResult(std::vector<double> scoreArr, double scoreAverage) {
    using namespace std;
    cout << "Scores\n";
    for (double score : scoreArr) {
        cout << score << " ";
    }
    cout << endl;
    cout << "Average of scores: " << scoreAverage << endl;
}

int main() {
    using namespace std;

    vector<double> scoreArr = getScore();
    double scoreAverage = getAverage(scoreArr);
    printResult(scoreArr, scoreAverage);
    return 0;
}