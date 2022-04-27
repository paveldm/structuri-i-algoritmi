#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void replace_del(char* x) {
	char* s = strtok(x, ", ");
	while (s) {
		int L = strlen(s);
		char x = s[L - 1];
		for (int i = L - 1; i > 0; i--) {
			s[i] = s[i - 1];
		}
		s[0] = x;
		string result;
		char prev;
		prev = s[0];
		result += s[0];
		for (int i = 1; i < strlen(s); i++) {
			if (s[i] != prev) {
				prev = s[i];
				result += s[i];
			}
		}
		cout << result << " ";
		s = strtok(NULL, ", ");
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	char str[1024];
	cout << "¬ведите предложение из слов, раздел€€ их пробелом или зап€той:" << "\n";
	gets_s(str);
	replace_del(str);
}