#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void inPlaceSelectionSort(int* A, int n) {// 제자리 선택 정렬
	int j, max, tmp = 0;

	for (int i = n - 1; i >= 1; i--) {
		max = i;
		for (j = i - 1; j >= 0; j--) {
			if (A[j] > A[max]) {
				max = j;
			}
		}
		tmp = A[i];
		A[i] = A[max];
		A[max] = tmp;
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

	inPlaceSelectionSort(A, n);

	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	free(A);

	return 0;
}