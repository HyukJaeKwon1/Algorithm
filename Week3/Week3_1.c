#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int heap[100];
int n;

void upHeap(int v) {
	int temp;
	int parent = v / 2;

	if (v == 1)
		return;

	if (heap[v] > heap[parent]) {
		temp = heap[v];
		heap[v] = heap[parent];
		heap[parent] = temp;
	}
	upHeap(parent);
}

void insertItem(int key) {
	n += 1;
	heap[n] = key;
	upHeap(n);
}


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

int removeMax() {
	int key = heap[1];
	heap[1] = heap[n];
	n--;
	downHeap(1);

	return key;
}

void printHeap() {
	for (int i = 1; i < n + 1; i++) {
		printf(" %d", heap[i]);
	}
	printf("\n");
}

int main() {
	char order;
	int key;
	int root = 0;

	while (1) {
		scanf("%c", &order);

		if (order == 'i') {
			scanf("%d", &key);
			insertItem(key);
			printf("0\n");
		}

		else if (order == 'd') {
			root = removeMax();
			printf("%d\n", root);
		}

		else if (order == 'p') {
			printHeap();
		}
		else if (order == 'q') {
			break;
		}
	}

}