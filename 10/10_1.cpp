#include <iostream>
#include <string>
#include <chrono>
using namespace std;

void prefix(int* arr, string str) {
	int i = 1, j = 0;
	while (i < str.length() - 1) {
		if (str[j] == str[i]) {
			arr[i] = j + 1;
			i++;
			j++;
		}
		else {
			if (j == 0) {
				arr[i] = 0;
				i++;
			}
			else {
				j = arr[j - 1];
			}
		}
	}
	//cout << "Массив суффиксов: ";
	//for (i = 0; i < 6; i++) {
	//	cout << arr[i] << " ";
	//}
	//cout << "\n";
}

void find_subs(int* arr, string a, string str) {
	int i = 0, j = 0;
	int cnt = 1;
	int x = 0, y = 0;
	while (i < a.length()) {
		if (a[i] == str[j]) {
			i++;
			j++;
			if (j == str.length()) {
				cnt++;
				x++;
			}
		}
		else {
			if (j > 0) {
				j = arr[j - 1];
			}
			else {
				i++;
			}
		}
		y++;
	}
	//cout << "В " << a << " присутствует " << cnt << " подстроки " << str;
	cout << x + y;
}

int main() {
	setlocale(LC_ALL, "ru");
	string str = "aabaab";
	int arr[6] = {0,0,0,0,0,0};
	prefix(arr, str);
	string a = "aabaabaaaaaabaabaabaabbaaab";
	for (int i = 0; i < 3; i++) {
		a += "aabaabaaaaaabaabaabaabbaaab";
	}
	int asd = 0;
	for (int i = 0; i < a.length(); i++) {
		asd++;
	}
	cout << "\n" << asd << "\n";
	auto start = chrono::high_resolution_clock::now();
	find_subs(arr, a, str);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "\n" << "Время потраченное на сортировку: " << duration.count() << " сек.";

}