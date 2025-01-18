#include <stdio.h>
#include <stdlib.h>

void inPlaceInsertionSort(int* A, int n) {
	int j, save, tmp = 0;

	for (int i = 1; i < n; i++) {
		save = A[i];
		j = i - 1;
		while ((j >= 0) && (A[j] > save)) {
			A[j + 1] = A[j];
			j -= 1;
		}
		A[j + 1] = save;
	}
}

int main() {
	int n;
	int* A;

	scanf("%d", &n);

	A = (int*)malloc(sizeof(int) * n);
	if (A == NULL) {
		printf("Not enough memory!");
		return -1;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		getchar();
	}

	inPlaceInsertionSort(A, n);

	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	free(A);

	return 0;
}