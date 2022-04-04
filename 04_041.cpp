#include <iostream>
using namespace std;

struct node {
	int key;
	char data;
	node* next;
};

// вывод списка
void outlist(node* L);

int main() {
	node* L = NULL; // вершина списка
	node* ptr1, * ptr2, * ptr3; // указатели на €чейки
	ptr1 = new node;
	ptr1->key = 7;
	ptr1->data = '*';
	ptr1->next = NULL;
	ptr2 = new node;
	ptr2->key = 2;
	ptr2->data = 'A';
	ptr2->next = NULL;
	ptr3 = new node;
	ptr3->key = 8;
	ptr3->data = 'B';
	ptr3->next = NULL;
	L = ptr2;
	L->next = ptr1;
	ptr1->next = ptr3;
	outlist(L);
}

void outlist(node* L) {
	node* q = L;
	while (q != NULL) {
		cout << q->key << " " << q->data << endl;
		q = q->next;
	}
}