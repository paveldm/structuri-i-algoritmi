#include <iostream>
#include <chrono>
using namespace std;

struct spec {
	string name;
	int kod;
} arr[6];

int func(spec* massiv, int key) {
	int mid, left = 0, right = 2;
	while (massiv[left].kod <= key && massiv[right].kod >= key)
	{
		if (massiv[right].kod == massiv[left].kod)
			break;
		mid = left + ((key - massiv[left].kod) * (right - left)) / (massiv[right].kod - massiv[left].kod);
		if (massiv[mid].kod < key)
			left = mid + 1;
		else if (massiv[mid].kod > key)
			right = mid - 1;
		else
			return mid;
	}
	if (massiv[left].kod == key)
		return left;
	if (massiv[right].kod == key)
		return right;
	return -1;
}


int main() {
	setlocale(LC_ALL, "ru");
	int code, res = 0;
	int j = 0;
	for (int i = 0; i < 3; i++) {
		cout << "Введите название вуза: ";
		cin >> arr[i].name;
		cout << "Введите код специальности: ";
		cin >> arr[i].kod;
	}
	cout << "\n" << "Поиск вуза по коду специальности: ";
	cin >> code;
	auto start = chrono::high_resolution_clock::now();
	res = func(arr, code);
	auto end = chrono::high_resolution_clock::now();
	cout << "Найденный вуз: " << arr[res].name;
	chrono::duration<float> duration = end - start;
	cout << "\n" << "Время потраченное на сортировку: " << duration.count() << " сек.";
}