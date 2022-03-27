#include <iostream>
#include <iomanip>
#define n 4
using namespace std;

int main()
{
	int arr[n][n];
	for (int i = 0; i < n; i++) {
		cout << "¬ведите " << i + 1 << " строку: ";
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int i = 0;
	for (int x = 0; x < n - 2; x++) {
		for (i = 0 + x; i < n - x; i++) {
			cout << arr[0 + x][i] << " ";
		}
		for (i = 1 + x; i < n - x; i++) {
			cout << arr[i][n - 1 - x] << " ";
		}
		for (i = n - 2 - x; i >= 0 + x; i--) {
			cout << arr[n - 1 - x][i] << " ";
		}
		for (i = n - 2 - x; i >= 1 + x; i--) {
			cout << arr[i][x] << " ";
		}
	}

}