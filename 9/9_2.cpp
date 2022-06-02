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
	int i = 0;
	while (arr[i].kod != code) {
		i++;
	}
	if (i < 3) {
		cout << arr[i].name;
	}
	else {
		return -1;
	}
}