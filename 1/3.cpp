#include <iostream>
#include <vector>
using namespace std;

//Предусловие.  a - массив, 0 <n<= N - размер массива (целое число) 
//Постусловие. Заполненный массив a
vector<int> inputArray(int n) {
	vector<int> a;
	cout << "Введите " << n << " чисел" << "\n";
	int L;
	for (int i = 0; i < n; i++) {
		cin >> L;
		a.push_back(L);
	}
	return a;
}
int func(vector<int> a, int cnt, int x, int sum, int n, int pos) {
	for (int i = 0; i < a.size(); i++) {
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
	for (int i = 0; i < n; i++) {
		if (a[i] == 7) {
			pos = i;
			for (int i = pos; i < n - 1; i++) {
				a[i] = a[i + 1];
			}
			--n;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}
int main() {
	setlocale(LC_ALL, "ru");
	int n;
	int p = 0, sum = 0, cnt = 0, x = 0;
	cout << "Введите  n = ";
	cin >> n;
	vector<int> l;
	l = inputArray(n);
	func(l, cnt, x, sum, n, p);
}