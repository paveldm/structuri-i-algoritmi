#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите количество чисел" << "\n";
	cin >> n;
	int *a = new int[n], i, sum = 0, cnt = 0, x = 0;
	cout << "Введите числа" << "\n";
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
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
		if (a[i] == 7) {
			cout << i << " ";
		}
		cnt = 0;
		sum = 0;

	}
}