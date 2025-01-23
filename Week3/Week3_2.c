#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int heap[100];
int n;

void downHeap(int v)
{
	int RightChild = 2 * v + 1;
	int LeftChild = 2 * v;

	if (LeftChild > n)
		return;

	int max = LeftChild;

	if (heap[max] < heap[RightChild]) {
		max = RightChild;
	}

	if (heap[v] < heap[max]) {
		int temp = heap[v];
		heap[v] = heap[max];
		heap[max] = temp;
	}
	downHeap(max);
}

void rBuildHeap(int i) {
	if (i > n) {
		return;
	}
	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);

	return;
}
void buildHeap() {
	for (int i = n / 2; i >= 1; i--) {
		downHeap(i);
	}
}

void printHeap() {
	for (int i = 1; i < n + 1; i++) {
		printf(" %d", heap[i]);
	}
	printf("\n");
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &heap[i]);
	}
	//rBuildHeap(1);
	buildHeap();
	printHeap();
}