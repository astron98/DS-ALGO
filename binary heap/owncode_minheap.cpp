#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

class Heap {

public:
	int capacity;
	int heap_size;
	int *heap;

	Heap(int size);
	int parent(int i) { return (i / 2) - 1; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }
	int getMin() { return heap[0]; }

	int extractMin();
	void heapify(int index, int size);
	void insertKey(int key);
	void deleteKey(int index);
	void decreaseKey(int index, int newVal);
	void heapSort();
	void printHeap();
};

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

Heap::Heap(int size) {
	int heap_size = 0;
	int capacity = size;
	heap = new int[size];
}

void Heap::heapify(int index, int size) {
	int smallest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && heap[left] < heap[smallest])
		smallest = left;

	if (right < size && heap[right] < heap[smallest])
		smallest = right;

	if (smallest != index) {
		swap(&heap[smallest], &heap[index]);
		heapify(smallest, size);
	}
}

void Heap::insertKey(int key) {
	if (heap_size == capacity) {
		cout << "Overflow!\n";
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	heap[i] = key;

	while ( i != 0 && heap[parent(i)] > heap[i]) {
		swap(&heap[i], &heap[parent(i)]);
		i = parent(i);
	}
}

int Heap::extractMin() {

	if (heap_size <= 0) return INT_MAX;

	if (heap_size == 1) {
		heap_size--;
		return heap[0];
	}

	int root = heap[0];
	heap[0] = heap[heap_size - 1];
	heap_size--;

	heapify(0, heap_size);

	return root;
}

void Heap::decreaseKey(int index, int newVal) {
	heap[index] = newVal;

	while (index != 0 && heap[parent(index)] > heap[index]) {
		swap(&heap[index], &heap[parent(index)]);
		index = parent(index);
	}
}

void Heap::deleteKey(int index) {

	decreaseKey(index, INT_MIN);
	extractMin();
}

void Heap::heapSort() {
	printf("Applying the heapSort...\n\n");
	//step 1: buildHeap, but here the heap property is already taken care by the insertKey(key)

	//step 2: swap every element with the last element and heapify.
	for (int i = heap_size - 1; i >= 0; i--) {
		swap(&heap[0], &heap[i]);
		heapify(0, i);
	}
}

void Heap::printHeap() {

	cout << "printing the MinHeap:\n";

	for (int i = 0; i < heap_size; i++) {
		cout << heap[i] << " ";
	}
	printf("\n");
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	Heap h(11);
	//or//
	//MinHeap h = new MinHeap(11);

	for(int i=0;i<7;i++){
		int x;
		cin >> x;
		h.insertKey(x);
	}
	// h.insertKey(3);
	// h.insertKey(2);
	// h.insertKey(1);
	// h.insertKey(15);
	// h.insertKey(5);
	// h.insertKey(4);
	// h.insertKey(45);

	h.heapSort();
	printf("printing the heap...\n");
	h.printHeap();

	/*
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();
	*/


	return 0;
}
