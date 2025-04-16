#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>

int priority(char operator_) {
    if (operator_ == '(') return 3;
    else if (operator_ == '*' || operator_ == '/') {
        return 1;
    } else if (operator_ == '+' || operator_ == '-') {
        return 2;
    } else {
        std::cout << operator_ << std::endl;
        throw std::invalid_argument("Not operator");
    }
}

void push(std::string & result, std::vector<char> & operators_, char operator_) {
    if (operator_ == ')') {
        while (operators_.back() != '(') {
            result += operators_.back();
            operators_.pop_back();
        }
        operators_.pop_back();
    } else if (operator_ == '(') {
        operators_.push_back(operator_);
    } else {
        while (!operators_.empty() && priority(operators_.back()) <= priority(operator_)) {
            result += operators_.back();
            operators_.pop_back();
        }
        operators_.push_back(operator_);
    }
}

int main() {
    using namespace std;
    vector<char> operators_;

    string input;
    cin >> input;

    string result = "";

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')') {
            push(result, operators_, input[i]);
        } else {
            result += input[i];
        }
    }

    while (!operators_.empty()) {
        result += operators_.back();
        operators_.pop_back();
    }

    cout << result << endl;
    return 0;
}