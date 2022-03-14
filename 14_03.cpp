#include <iostream>
using namespace std;
const int n = 4, m = 4;
//результат true, если массив из нулей
bool nullRow(int* r, int m);
//удаление строки из нулей
void delRows(int x[][m], int &n, int m);
//вывод двумерного массива
void outArray2(int x[][m], int n, int m);
void outDiagonal(int x[][m], int n, int m);
int main() {
	int x[n][m] = { {1,2,3,7},
					{0,0,0,0},
					{4,5,6,8},
					{0,0,0,0}
				};
	int nx = n;
	delRows(x, nx, m);
	outArray2(x, nx, m);
	outDiagonal(x, nx, m);
}
void outDiagonal(int x[][m], int n, int m) {
	for (int i = 0; i < n; i++) {
		cout << x[i][i] << " ";
	}
	cout << "\n";
}
bool nullRow(int* r, int m) {
	for (int i = 0; i < m; i++) {
		if (r[i] != 0) {
			return false;
		}
	}
	return true;
}
void delRows(int x[][m], int& n, int m) {
	for (int i = 0; i < n; i++) {
		if (nullRow(x[i], m) == true) {
			for (int i1 = i; i1 < n - 1; i1++) {
				for (int j = 0; j < m; j++) {
					x[i1][j] = x[i1 + 1][j];
				}
			}
			n--;
			i--;
		}
	}
}
void outArray2(int x[][m], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << x[i][j] << " ";
		}
	}
	cout << "\n";

}