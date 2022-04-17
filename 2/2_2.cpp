#include <iostream>
using namespace std;

int** inputArr(int n) {
	int** x = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		cout << "Введите " << i + 1 << " строку: ";
		x[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
		{
			cin >> x[i][j];
		}
	}

	return x;
}

void inputRandArray(int **x, int n) {
	for (int i = 0; i < n; i++) {
		x[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = rand() % 100 + 1;
		}
	}
}

void outSpiral(int **x, int n) {
	int i = 0;
	for (int ind = 0; ind < n - 1; ind++) {
		for (i = ind; i < n - ind; i++) {
			cout << x[ind][i] << " ";
		}
		for (i = 1 + ind; i < n - ind; i++) {
			cout << x[i][n - 1 - ind] << " ";
		}
		for (i = n - 2 - ind; i >= ind; i--) {
			cout << x[n - 1 - ind][i] << " ";
		}
		for (i = n - 2 - ind; i >= 1 + ind; i--) {
			cout << x[i][ind] << " ";
		}
	}
}

void outArray(int **x, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << x[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Введите размер n масива n*n: ";
	int n;
	cin >> n;

	// Для двумерного динамического массива с введенными с клавиатуры элементами
	int** x = inputArr(n);

	// Для двумерного динамического массива со случайными элементами
	int** x = new int*[n];
	inputRandArray(x, n);

	outSpiral(x, n);
	outArray(x, n);
}