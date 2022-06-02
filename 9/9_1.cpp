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
		cout << "Введите название вуза: ";
		cin >> arr[i].name;
		cout << "Введите код специальности: ";
		cin >> arr[i].kod;
	}
	cout << "\n" << "Поиск вуза по коду специальности: ";
	cin >> code;
	for (int i = 0; i < 100; i++) {
		if (arr[i].kod == code) {
			j = 1;
			if (j == 1) {
				cout << "\nВуз с этой специальностью: " << arr[i].name << "\n";
			}
		}
	}
	if (j == 0) {
		cout << "Вуз не найден" << "\n";
	}
	return 0;
}