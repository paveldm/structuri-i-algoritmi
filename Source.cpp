#include <iostream>
#include "time.h"
using namespace std;
const int N = 1000;

void inputArray(int* x, int n);
void outArray(int* x, int n);
void inputRandArray(int* x, int n);


int main() {
	setlocale(LC_ALL, "ru");
	int a[N], n;
	cout << "Введите  n = ";
	cin >> n;
	if (n <= 0 || n > N) {
		cout << "n <= 0 || n > N";
		return 1;
	}
	//inputArray(a, n);
	inputRandArray(a, n);
	outArray(a, n);

	return 0;
}

void inputArray(int* x, int n) {
	cout << "Введите " << n << " чисел" << "\n";
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
}

void outArray(int* x, int n) {
	cout << "Массив " << n << " чисел" << "\n";
	for (int i = 0; i < n; i++) {
		cout << x[i] << ' ';
	}
}

void inputRandArray(int* x, int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		x[i] = rand() % 100;
	}
}
