#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool Operator(char in_x) {
	return in_x >= 'a' and in_x <= 'z';
}

string in(string str) {
	stack<string> stek;
	for (int i = 0; str[i] != 0; i++) {
		if (Operator(str[i])) {
			string op(1, str[i]);
			stek.push(op);
		}
		else {
			string x = stek.top();
			stek.pop();
			string y = stek.top();
			stek.pop();
			stek.push("(" + y + str[i] + x + ")");
		}
	}
	return stek.top();
}

int main() {
	setlocale(LC_ALL, "RUS");
	string post = "xyz^+mnk/-*p+";
	cout << "Постфиксная нотация: " << post << endl;
	cout << "Инфиксная нотация: " << in(post);
	return 0;
}