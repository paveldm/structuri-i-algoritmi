#include <iostream>
using namespace std;

struct node {
	int key;
	char data;
	node* next;
};

// ����� ������
void outlist(node* L);

// �������� ������ �� n ����� ��������� ��������� �(n^2)
void createList1(node*& L, int n) {
	node* q, * q1 = L; // q1 - ��������� �� ��������� ����
	cout << "������� " << n << " �����: ";
	for (int i = 1; i <= n; i++) {
		q = new node;
		cin >> q->key;
		q->next = NULL;
		if (L == NULL) {
			L = q;
			q1 = q;
		}
		else {
			q1->next = q;
			q1 = q;
		}
	}
}

// ����� ���� � �������� ��������� key � ������� �� ���� ���������
node* findKey(node* L, int key) {
	node* q = L;
	while (q != NULL) {
		if (q->key == key) return q;
		q = q->next;
	}
	return NULL;
}

int main() {
	setlocale(LC_ALL, "ru");
	node* L = NULL;
	createList1(L, 5);
	outlist(L);
	node* rez = findKey(L, 10);
	if (rez)
		cout << rez->key << " " << rez;
	else
		cout  << "key isnt " << rez;
}

void outlist(node* L) {
	node* q = L;
	while (q != NULL) {
		cout << q->key << endl;
		q = q->next;
	}
}