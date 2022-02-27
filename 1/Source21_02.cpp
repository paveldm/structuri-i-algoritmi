#include <iostream>
#include "time.h"
using namespace std;
const int N = 1000;

void inputArray(int* x, int n);
void outArray(int* x, int n);
void inputRandArray(int* x, int n);
//n<=N, 0<p<=n
//”далить значение в позиции pos
void erase(int* x, int& n, int pos);
//¬ставить новое значение в позицию pos
void insert(int* x, int& n, int pos, int value);

void eraseAllIf(int* x, int& n);

int main() {
	setlocale(LC_ALL, "ru");
	int a[N], n, p = 1;
	cout << "¬ведите  n = ";
	cin >> n;
	if (n <= 0 || n > N) {
		cout << "n <= 0 || n > N";
		return 1;
	}
	inputArray(a, n);
	//inputRandArray(a, n);
	outArray(a, n);
	
	/*
	if (n > N || p > n) { cout << "No insert"; return 2; }
	insert(a, n, p, 123);
	p = 0;
	if (n > N || p > n) { cout << "No insert"; return 2; }
	insert(a, n, p, 123);
	p = n - 1;
	if (n > N || p > n) { cout << "No insert"; return 2; }
	insert(a, n, p, 123);
	outArray(a, n);
	*/
	
	p = 2;
	erase(a, n, p);
	erase(a, n, 0);
	erase(a, n, n + 1);
	outArray(a, n);
	

	//eraseAllIf(a, n);
	//outArray(a, n);
	return 0;
}

//удаление всех четных чисел из массива (1 2 3 4 2 2 2 5 7)
void eraseAllIf(int* x, int& n) {
	for (int i = 0; i < n; i++) {
		if (x[i] % 2 == 0) {
			x[i] = x[i + 1];
		}
	}
	--n;
}

void erase(int* x, int& n, int pos) {
	//сдвиг влево части массива от (pos)
	for (int i = pos; i < n - 1; i++) {
		x[i] = x[i + 1];
	}
	--n;
}
void insert(int* x, int& n, int pos, int value) {
	//сдвиг вправо части массива (до pos)
	for (int i = n; i > pos; i--) {
		x[i] = x[i - 1];
	}
	x[pos] = value;
	n++;
}


void inputArray(int* x, int n) {
	cout << "¬ведите " << n << " чисел" << "\n";
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
}

void outArray(int* x, int n) {
	cout << "ћассив " << n << " чисел" << "\n";
	for (int i = 0; i < n; i++) {
		cout << x[i] << ' ';
	}
	cout << "\n";
}

void inputRandArray(int* x, int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		x[i] = rand() % 100;
	}
}
