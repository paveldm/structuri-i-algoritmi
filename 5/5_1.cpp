#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

void creat_list(node*& L, int n) {
	cout << "Введите числа: ";
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

void print_list(node* L) {
	cout << "Вывод списка: ";
	node* q = L;
	while (q != NULL) {
		cout << q->data << " ";
		q = q->next;
	}
	cout << "\n";
}

bool same_elem(node* L) {
	node* q = L;
	while (q->next != NULL) {
		while (q->next != NULL) {
			q = q->next;
			if (L->data == q->data) {
				return true;
			}
		}
	}
}

struct node* find_max(node* L) {
	node* q = L;
	for (; q != NULL; q = q->next) {
		if (q->data > L->data) {
			L = q;
		}
	}
	return L;
}

struct node * del_max(node* L, node* del) {
	node* q = L;
	while (q->next != del) {
		q = q->next;
	}
	q->next = del->next;
	free(del);
	return(q);
}

int main() {
	setlocale(LC_ALL, "ru");
	node* L = NULL;
	int n;
	bool b = false;
	cout << "Введите количество чисел: ";
	cin >> n;

	creat_list(L, n);
	//b = same_elem(L);
	//if (b) {
	//	cout << "В списке есть два одинаковых элемента";
	//}
	//else {
	//	cout << "В списке нет одинаковых элементов";
	//}
	cout << "\n";
	node* max_n = find_max(L);
	del_max(L, max_n);
	print_list(L);
}