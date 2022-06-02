#include <iostream>
#include <stack>
#include <string>
using namespace std;

int oper(string left, char operation, string right) {
	int a = stoi(left);
	int b = stoi(right);
	switch (operation) {
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '+':
		return a + b;
	case '-':
		return a - b;
	default:
		return 0;
	}
}

int print(string post) {
	stack<string> stek;
	for (char elem : post) {
		if (isdigit(elem))
			stek.push(string(1, elem));
		else {
			string b = stek.top();
			stek.pop();
			string a = stek.top();
			stek.pop();
			int res = oper(a, elem, b);
			stek.push(to_string(res));
		}
	}
	return stoi(stek.top());
}

int main() {
	setlocale(LC_ALL, "ru");
	string str = "723*582/-+1-+";
	cout << "Исходно выражение: " << str << endl;
	cout << "Результат: " << print(str) << endl;
}
