#include <iostream>
#include <chrono>
using namespace std;

void Merge(int* a, int l, int r) {
	int i = l;
	int mid = l + (r - l) / 2;
	int j = mid + 1;
	int pos = 0, sravn = 0, replace = 0;
	int* b = new int[r - l + 1];
	while (i <= mid and j <= r) {
		if (a[i] < a[j]) {
			b[pos++] = a[i++];
		}
		else
			b[pos++] = a[j++];
	}
	while (i <= mid) {
		b[pos++] = a[i++];
	}
	while (j <= r) {
		b[pos++] = a[j++];
	}
	for (int i = l; i <= r; i++) {
		a[i] = b[i - l];
	}
}

void MergeSort(int* A, int l, int r) {
	int mid = l + (r - l) / 2;
	if (r <= l) {
		return;
	}
	MergeSort(A, l, mid);
	MergeSort(A, mid + 1, r);
	Merge(A, l, r);
}

void input_x(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
}

void input_rand(int x[], int n) {
	for (int i = 0; i < n; i++) {
		x[i] = rand() % 100 + 1;
	}
}

void output_x(int x[], int n) {
	int j = 0;
	for (int i = 1; i < n; i++) {
		cout << x[i] << " ";
	}
}

void main() {
	setlocale(LC_ALL, "ru");
	int i, n;
	cout << "¬ведите размер массива: ";
	cin >> n;
	int* x = new int[n];
	//cout << "¬ведите " << n << " чисел: ";
	//input_x(x, n);
	input_rand(x, n);
	auto start = chrono::high_resolution_clock::now();
	MergeSort(x, 0, n);
	auto end = chrono::high_resolution_clock::now();
	cout << "\nќтсортированный массив: ";
	output_x(x, n);
	chrono::duration<float> duration = end - start;
	cout << "\n" << "¬рем€ потраченное на сортировку: " << duration.count() << " сек.";
}