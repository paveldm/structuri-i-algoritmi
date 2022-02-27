#include <iostream>
using namespace std;

const int N = 1000;
void inputArray(int* a, int n) {
	cout << "¬ведите " << n << " чисел" << "\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void func(int* a, int cnt, int x, int sum, int n) {
	int i;
	for (i = 0; i < n; i++) {
		x = a[i];
		while (x != 0) {
			x /= 10;
			cnt += 1;
		}
		for (int j = 0; j <= cnt; j++) {
			while (a[i] > 9) {
				sum = 0;
				while (a[i] != 0) {
					sum += a[i] % 10;
					a[i] /= 10;
				}
				a[i] = sum;
			}

		}
		cnt = 0;
		sum = 0;
	}
}

void erase(int* x, int& n, int pos) {
	//сдвиг влево части массива от (pos)
	for (int i = pos; i < n - 1; i++) {
		x[i] = x[i + 1];
	}
	--n;
}

void outArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << "\n";
}

int main() {
	setlocale(LC_ALL, "ru");
	int n;
	int a[N], i, p = 0, sum = 0, cnt = 0, x = 0;

	cout << "¬ведите  n = ";
	cin >> n;
	inputArray(a, n);
	func(a, cnt, x, sum, n);

	for (int i = 0; i < n; i++) {
		if (a[i] == 7) {
			p = i;
			erase(a, n, p);
		}
	}


	outArray(a, n);
}