#include <iostream>
using namespace std;

const int N = 1000;

//Предусловие.  a - массив, 0 <n<= N - размер массива (целое число) 
//Постусловие. Заполненный массив n
void inputArray(int* a, int n) {
	cout << "Введите " << n << " чисел" << "\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

//Предусловие. Заполненный массив n, элементы массива - целые числа
//Постусловие. Индекс числа в массиве с цифровым корнем, равным 7 - целое число
void func(int* a, int cnt, int x, int sum, int n) {
	int i;
	for (i = 0; i < n; i++) {
		x = a[i];
		for (int j = 0; j <= n; j++) {
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

int main() {
	setlocale(LC_ALL, "ru");

	int a[N], i, n, sum = 0, cnt = 0, x = 0;
	cout << "Введите размер массива: ";
	cin >> n; // ввод числе с клавиатуры
	if (n < 0 or n > N) {
		cout << "Неверный размер массива";
		return 1;
	}

	inputArray(a, n);
	func(a, cnt, x, sum, n);
}