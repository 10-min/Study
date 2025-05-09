#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

char X[] = "heroically";
char Y[] = "scholarly";
int cnt_call = 0;

int LCS_recursive(int m, int n) {
    // printf("(%d, %d) ", m, n);
    cnt_call++;
    if (m == 0 || n == 0)
        return 0;
    else if (X[m] == Y[n]) {
        // printf("%c", X[m]);
        return LCS_recursive(m - 1, n - 1) + 1;
    }
    else {
        return MAX(LCS_recursive(m - 1, n), LCS_recursive(m, n - 1));
    }
}
void print_LCS(int (*B)[10], char X[], int i, int j) {
    if (i == 0 || j == 0)
        return;
    
    if (B[i][j] == 2) {
        print_LCS(B, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if (B[i][j] == 1) {
        print_LCS(B, X, i - 1, j);
    }
    else {
        print_LCS(B, X, i, j - 1);
    }
}

int main(void) {
    int m = 11;
    int n = 10;
    int table[11][10] = { 0 };
    int trace[11][10] = { 0 }; // ��: 0, �� : 1, �� : 2

    // top-down
    printf("\n\nSolution by a recursive function: %d\n",
        LCS_recursive(m - 2, n - 2));
    printf("The recursive function is called %d times\n", cnt_call);

    // bottom-up
    for (int i = 0; i < m; i++)
        table[i][0] = 0;

    for (int j = 0; j < n; j++)
        table[0][j] = 0;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                trace[i][j] = 2;
            }
            else {
                if (table[i - 1][j] > table[i][j - 1]) {
                    table[i][j] = table[i - 1][j];
                    trace[i][j] = 1;
                }
                else {
                    table[i][j] = table[i][j - 1];
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    print_LCS(trace, X, m-1, n-1);

    // Exercise
    // From the dynamic programming solution, modify the code to find a largest
    // common subsequence.

    return 0;
}