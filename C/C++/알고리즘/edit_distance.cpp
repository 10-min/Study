#include <iostream>
#include <string>

using namespace std;
int min(int a, int b) {
    int min_value;
    if (a < b) {
        min_value = a;
    } else {
        min_value = b;
    }

    return min_value;
}
int main(void) {
    string X = "algori";
    string Y = "al";
    int X_l = X.length() + 1;
    int Y_l = Y.length() + 1;
    int cp = 0;
    int is = 1;
    int del = 1;

    int**D = new int*[Y_l];
    
    for (int i = 0; i < Y_l; i++) {
        D[i] = new int[X_l];
    }

    for (int i = 0; i < X_l; i++) {
        D[0][i] = i;
    }
    for (int i = 0; i < Y_l; i++) {
        D[i][0] = i;
    }


    for (int i = 1; i < Y_l; i++) {
        for (int j = 1; j < X_l; j++) {
            if (Y[i-1] == X[j-1]) {
                D[i][j] = D[i-1][j-1];
            } else {
                D[i][j] = min(D[i][j-1] + del, D[i-1][j] + is);
            }
        }
    }

    for (int i = 0; i < Y_l; i++) {
        for (int j = 0; j < X_l; j++) {
            cout << D[i][j] << ' ';
        }
        cout << endl;
    }

    


    return 0;
}