#include <iostream>
using namespace std;

//Предусловие.  a - массив, 0 <n<= N - размер массива (целое число) 
//Постусловие. Заполненный массив n
void inputArray(int* a, int n) {
	cout << "Введите " << n << " чисел" << "\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

//Предусловие. Заполненный массив n, элементы массива - целые числа
//Постусловие. Измененный массив n из целых чисел
void func(int* a, int cnt, int x, int sum, int n, int p) {
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

//Предусловие. Измененный массив n из целых чисел
//Постусловие. Массив из n+1 элементов
void insert(int* a, int& n, int p) {
	for (int i = n; i > p; i--) {
		a[i] = a[i - 1];
	}
	a[p] = 0;
	n++;
}

//Предусловие. Массив из n+1 элементов
//Постусловие. Вывод на экран элементов массива
void outArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << "\n";
}

int main() {
	setlocale(LC_ALL, "ru");
	int n, i, p = 0, sum = 0, cnt = 0, x = 0;

	cout << "Введите  n = ";
	cin >> n;
	int* a = new int[n];

	inputArray(a, n);
	func(a, cnt, x, sum, n, p);
	
	//Проверка равенства цифрового корня числа и 7
	for (int i = 0; i < n; i++) {
		if (a[i] == 7) {
			p = i;
		}
	}
	insert(a, n, p);
	outArray(a, n);
}