#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

void creat_list(node*& L, int n) {
	node* q, *q1;
	for (int i = 1; i <= n; i++) {
		q = new node;
		q->next = NULL;
		cin >> q->data;
		if (L == NULL) {
			L = q;
		}
		else {
			q1 = L;
			while (q1->next != NULL) {
				q1 = q1->next;
			}
			q1->next = q;
		}
	}
}

bool same_elem(node* L) {
	while (L->next) {
		node* tec = L->next;
		while (tec) {
			if (tec->data == L->data) {
				return true;
			}
			L = L->next;
		}
		return false;
	}
}
void print_list(node* L) {
	node* q = L;
	while (q != NULL) {
		cout << q->data << " ";
		q = q->next;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	node* L = NULL;
	int n;
	bool b = false;
	cout << "¬ведите количество чисел: ";
	cin >> n;

	creat_list(L, n);
	print_list(L);
	b = same_elem(L);
	if (b) {
		cout << "12";
	}
	else {
		cout << "false";
	}
}