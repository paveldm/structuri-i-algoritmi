#include <iostream>
using namespace std;

struct node {
	int key;
	char data;
	node* next;
};

// вывод списка
void outlist(node* L);

// создание списка из n узлов сложность алгоритма ќ(n^2)
void createList(node* &L, int n) {
	node* q, * q1;
	cout << "¬ведите " << n << " чисел: ";
	for (int i = 1; i <= n; i++) {
		q = new node;
		q->next = NULL;
		cin >> q->key;
		if(L == NULL){
			L = q;
		}
		else {
			// найти указатель на последний узел
			q1 = L;
			while (q1->next != NULL) {
				q1 = q1->next;
			}
			q1->next = q;
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	node* L = NULL;
	createList(L, 5);
	outlist(L);
}

void outlist(node* L) {
	node* q = L;
	while (q != NULL) {
		cout << q->key << endl;
		q = q->next;
	}
}