#include <iostream>
#include <string>
#define INF 10e9
using namespace std;

void recursive_print(int i, int j, int root[][6]) {
    if (j == i - 1) {
        return;
    }
    int root_number = root[i][j];
    cout << "k" << to_string(root_number);

    if (i == j) {
        return;
    } else {
        cout << "(";

        recursive_print(i, root_number - 1, root);
        cout << ", ";
        recursive_print(root_number + 1, j, root);

        cout << ")";
    }
}
int main(void) {
    float pi[] = {0, 0.25, 0.2, 0.05, 0.2, 0.3}; // index: 0~4 => 1~5
    float w[7][6] = {0};
    float e[7][6] = {0};
    int root[7][6] = {0};

        
    for (int col = 0; col <= 5; col++) {
        for (int row = 1; row <= 6-col; row++) {
            int i = row;
            int j = col + row - 1;
            if (j == i - 1) {
                w[i][j] = 0;
                continue;
            } else if (i <= j) {
                float sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += pi[k];
                }
                w[i][j] = sum;
            }
        }
    }
    
    for(int col = 0; col <= 5; col++) {
        for (int row = 1; row <= 6-col; row++) {
            int i = row;
            int j = col + row - 1;
            if (j == i - 1)  {
                e[i][j] = 0;
            } else if (i <= j) {
                float min = INF;
                for (int k = i; k <= j; k++) { // k = r
                    if (min > (e[i][k-1] + e[k+1][j] + w[i][j])) {
                        min = (e[i][k-1] + e[k+1][j] + w[i][j]);
                        root[i][j] = k;
                    }
                }
                e[i][j] = min;
            }
        }
        
    }

    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << root[i][j] <<' ';
        }
        cout << endl;
    }
    
    recursive_print(1, 5, root);
    

    
    return 0;
}