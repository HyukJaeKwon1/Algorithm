#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Heap[100];
int n;

void downHeap(int v, int last)
{
	int l_child = 2 * v;
	int r_child = 2 * v + 1;

	if (l_child > last) return;

	int larger = l_child;

	if (r_child <= last) {
		if (Heap[larger] < Heap[r_child]) {
			larger = r_child;
		}
	}
	if (Heap[v] < Heap[larger]) {
		int temp = Heap[v];
		Heap[v] = Heap[larger];
		Heap[larger] = temp;
	}
	downHeap(larger, last);
}

void buildHeap() {
	for (int i = n / 2; i >= 1; i--) {
		downHeap(i, n);
	}
}
void inPlaceHeapSort() {
	for (int i = n; i >= 2; i--) {
		int temp = Heap[1];
		Heap[1] = Heap[i];
		Heap[i] = temp;


		downHeap(1, i - 1);
	}
}


int main() {
	scanf("%d", &n);

	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &Heap[i]);
	}

	buildHeap();
	inPlaceHeapSort();
	for (int i = 1; i < n + 1; i++) {
		printf(" %d", Heap[i]);
	}
	printf("\n");
}