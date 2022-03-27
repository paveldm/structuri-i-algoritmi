#include <iostream>
#include <time.h>
using namespace std;
const int rows = 100;
const int cols = 100;

void inputArray(int x[][cols], int n) {

	for (int i = 0; i < n; i++) {
		cout << "¬ведите " << i + 1 << " строку: ";
		for (int j = 0; j < n; j++) {
			cin >> x[i][j];
		}
	}
}

void inputRandArray(int x[][cols], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = rand() % 100 + 1;
		}
	}
}

void outSpiral(int x[][cols], int n) {
	int i = 0;
	for (int ind = 0; ind < n - 2; ind++) {
		for (i = 0 + ind; i < n - ind; i++) {
			cout << x[0 + ind][i] << " ";
		}
		for (i = 1 + ind; i < n - ind; i++) {
			cout << x[i][n - 1 - ind] << " ";
		}
		for (i = n - 2 - ind; i >= 0 + ind; i--) {
			cout << x[n - 1 - ind][i] << " ";
		}
		for (i = n - 2 - ind; i >= 1 + ind; i--) {
			cout << x[i][ind] << " ";
		}
	}
}

void outArray(int x[][cols], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << x[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int x[rows][cols];
	cout << "¬ведите размер n масива n*n: ";
	int n;
	cin >> n;
	inputArray(x, n);
	//inputRandArray(x, n);
	outSpiral(x, n);
	//outArray(x, n);
}