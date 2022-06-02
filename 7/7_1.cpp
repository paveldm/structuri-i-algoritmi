#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool Operator(char x) {
	return x == '*' or x == '/' or
		x == '+' or x == '-';
}

int Priority(char x) {
	if (x == '+' or x == '-') {
		return 1;
	}
	if (x == '*' or x == '/') {
		return 2;
	}
	return 0;
}

string postn(string in) {
	string post;
	stack<char> stek;
	for (char element : in) {
		if (isalpha(element)) {
			post += element;
		}
		if (Operator(element)) {
			if (Priority(stek.top()) < Priority(element)) {
				stek.push(element);
			}
			else {
				while (!stek.empty() and stek.top() != '(' and !(Priority(stek.top()) < Priority(element))) {
					post += stek.top();
					stek.pop();
				}
				stek.push(element);
			}
		}
		if (element == '(') {
			stek.push(element);
		}
		if (element == ')') {
			while (!stek.empty() and stek.top() != '(') {
				post += stek.top();
				stek.pop();
			}
			if (stek.top() == '(') {
				stek.pop();
			}
		}
	}
	return post;
}
int main() {
	setlocale(LC_ALL, "RUS");
	string in = "((a*(d-e)+(f+g)/c)+(k*l-s/m))";
	cout << "Инфиксная нотация: " << in << endl;
	string post = postn(in);
	cout << "Выражение, записанное в постфиксной нотации: " << post << endl;
}
