#include <iostream>
using namespace std;

struct spec {
	string name;
	int kod;
} arr[100];

int main() {
	setlocale(LC_ALL, "ru");
	int code;
	int j = 0;
	for (int i = 0; i < 3; i++) {
		cout << "������� �������� ����: ";
		cin >> arr[i].name;
		cout << "������� ��� �������������: ";
		cin >> arr[i].kod;
	}
	cout << "\n" << "����� ���� �� ���� �������������: ";
	cin >> code;
	for (int i = 0; i < 100; i++) {
		if (arr[i].kod == code) {
			j = 1;
			if (j == 1) {
				cout << "\n��� � ���� ��������������: " << arr[i].name << "\n";
			}
		}
	}
	if (j == 0) {
		cout << "��� �� ������" << "\n";
	}
	return 0;
}