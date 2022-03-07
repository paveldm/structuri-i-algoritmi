#include <iostream>
using namespace std;

void del(int* x, int& n);
void del1(int* x, int& n);
int main() {
	int* a = new int;
	*a = 10;
	cin >> *a;

	int n = 10;
	int x[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int* y = new int[n] {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int* z = y;
	cout << x << " " << x[5] << " " << *(x + 5) << endl;
	//x = x + 5;
	y = y + 5;
	cout << y - z;
	cout << y << " " << *y;
	for (int i = 0; i < n; i++) {
		cout << x << " " << *(x + i) << " ";
	}
	//y = x;
	for (int i = 0; i < n; i++) {
		cout << y << " " << y[i] << " ";
	}
	del(z, n);
	for (int i = 0; i < n; i++) {
		cout << y[i] << " ";
	}
	delete[]y;
}

void del(int* x, int& n) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		x[j] = x[i];
		if (x[i] % 2 != 0) {
			j++;
		}
	}
	n = j;
}

void del1(int* x, int& n) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] % 2 == 0) {
			x[j] = x[j - i];
		}
	}
	n = j;
}