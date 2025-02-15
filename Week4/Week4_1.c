#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int heap[100];
int n;

void upHeap(int i) {
	int temp;
	int parent = i / 2;

	if (i == 1)
		return;

	if (heap[i] > heap[parent]) {
		temp = heap[i];
		heap[i] = heap[parent];
		heap[parent] = temp;
	}
	upHeap(parent);
}


void insertItem(int key) {
	n += 1;
	heap[n] = key;
	upHeap(n);
}

void downHeap(int i)
{
	int RightChild = 2 * i + 1;
	int LeftChild = 2 * i;

	if (LeftChild > n)
		return;

	int max = LeftChild;

	if (RightChild <= n)
	{
		if (heap[max] < heap[RightChild]) {
			max = RightChild;
		}
	}

	if (heap[i] < heap[max]) {
		int temp = heap[i];
		heap[i] = heap[max];
		heap[max] = temp;
	}
	downHeap(max);
}

void inPlaceHeapSort() {
	for (int i = n; i >= 2; i--) {
		int temp = heap[1];
		heap[1] = heap[i];
		heap[i] = temp;
		n--;
		downHeap(1);
	}

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


void printArray() {
	for (int i = 1; i < n + 1; i++) {
		printf(" %d", heap[i]);
	}
}

int main() {

	int key = 0;
	int cnt = 0;
	int origin;
	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &key);
		insertItem(key);
	}
	origin = n;
	inPlaceHeapSort();
	n = origin;
	printArray();
}