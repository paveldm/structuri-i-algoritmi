#include <iostream>
#include <chrono>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int* index;
		int j = 0;
	int* arr, n;
		int key;
		cout << "������� ���������� ��������� �������: ";
	cin >> n;
	index = arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = 1 + rand() % n;
	}
	cout << endl << "������� ����� �� �������: ";
	cin >> key;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++) {
			if (arr[i] == key) {
				continue;
			}
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "\n" << "����� ����������� �� ����������: " << duration.count() << " ���.";
}