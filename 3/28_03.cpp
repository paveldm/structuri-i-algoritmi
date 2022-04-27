#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	char str[1024];
	int i;
	for (i = 0; i < 10; i++) {
		str[i] = 'A' + i;
	}
	str[i] = '\0';
	i = 0;
	while (str[i] != '\0') {
		i++;
	}
	puts("length(str)="); cout << i << "\n";
	puts(str);
	puts("¬ведите текст");
	gets_s(str);
	puts(str);
	char* ptr1;
	char* word;
	char** arrayWords = NULL;
	//char word[100] = "\0";
	int n;
	i = 0;
	while (strlen(str) != 0) {

		ptr1 = strchr(str, ' ');
		//puts(ptr1);
		n = ptr1 - str;
		if (n) {
			if (i == 0) {
				arrayWords = (char**)malloc(sizeof(char*));			}
			else {
				i++;
				arrayWords = (char**)realloc(arrayWords, sizeof(char*) * i);
			}
		}
		word = (char*)malloc(sizeof(char) * (n + 1));
		//word = new char[n + 1];
		if (word != 0) {
			strncpy(word, str, n);
			word[n] = '\0';
			puts(word);
			strcpy(str, ptr1 + 1);
			delete []word;
		}

	}
}