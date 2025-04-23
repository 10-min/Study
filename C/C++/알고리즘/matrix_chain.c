#include <stdio.h>
int m[5][5];
int k_index[5][5];

int recursive_matrix(int* p, int i, int j) {
	if (i == j)
		return 0;

	m[i-1][j-1] = 2147483647; //infinity

	for (int k = i; k < j; k++) {
		int q = recursive_matrix(p, i, k) + recursive_matrix(p, k + 1, j) + p[i - 1] * p[k] * p[j];
		if (q < m[i-1][j-1]) {
			m[i - 1][j - 1] = q;
			k_index[i - 1][j - 1] = k;
		}

	}
	return m[i-1][j-1];


}
int main() {
	int input[] = { 4, 3, 2, 10, 6, 5 }; // A1 ~ A5 row, col value
	recursive_matrix(input, 1, 5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%5d", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%5d", k_index[i][j]);
		}
		printf("\n");
	}


	
}