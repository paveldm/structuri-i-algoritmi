#ifndef _4_STATIC_H
#define _4_STATIC_H
#include <iostream>
#include <string>
#include <clocale>
#include <vector>
#include <Windows.h>
using namespace std;
const int n = 100;
struct Employee {
	int id;
	string fam;
	string name;
	string o;
	int pos;
	int date;
};

vector<Employee> input_pers(int x) {
	vector<Employee> a(n);
	for (int i = 0; i < x; i++) {
		cout << "������� ������ " << i + 1 << "-�� ����������:" << "\n";
		cout << "��������� �����: "; cin >> a[i].id;
		cout << "������� � ��������: "; cin >> a[i].fam >> a[i].name >> a[i].o;
		cout << "��� ���������� ���������: "; cin >> a[i].pos;
		cout << "���� ����������� �� ������: "; cin >> a[i].date;
		cout << "\n";
	}
	return a;
}

//void input_pers(vector<Employee> a, int x) {
//	for (int i = 0; i < x; i++) {
//		cout << "������� ������ " << i + 1 << "-�� ����������:" << "\n";
//		cout << "��������� �����: "; a.push_back(a[i].id);
//		cout << "������� � ��������: "; cin >> a[i].fam >> a[i].name >> a[i].o;
//		cout << "��� ���������� ���������: "; cin >> a[i].pos;
//		cout << "���� ����������� �� ������: "; cin >> a[i].date;
//		cout << "\n";
//	}
//}

void output_pers(vector<Employee> emp, int x) {
	for (int i = 0; i < x + 1; i++) {
		cout << "������� � ��������: " << emp[i].fam << " " << emp[i].name << " " << emp[i].o << "\n";
		cout << "��������� �����: " << emp[i].id << "\n";
		cout << "��� ���������� ���������: " << emp[i].pos << "\n";
		cout << "���� ����������� �� ������: " << emp[i].date << "\n";
		cout << "\n";
	}
}

void sort(Employee* emp, int x) {
	cout << "\n";
	for (int i = 0; i < x; i++) {
		int min = i;
		for (int j = i + 1; j < x + 1; j++) {
			if (emp[j].pos < emp[min].pos) {
				min = j;
			}
		}
		if (min != i) {
			swap(emp[i], emp[min]);
		}
	}
}
void add_pers(Employee* a, int x) {
	cout << "������� ������ ����������:" << "\n";
	cout << "��������� �����: "; cin >> a[x].id;
	cout << "������� � ��������: "; cin >> a[x].fam >> a[x].name >> a[x].o;
	cout << "��� ���������� ���������: "; cin >> a[x].pos;
	cout << "���� ����������� �� ������: "; cin >> a[x].date;
	cout << "\n";
	cout << "���������� ������ ����� ��������� � ����� �� ����������" << "\n";
}

void replace_pos(Employee* emp, int x, int old_pos, int new_pos) {
	for (int i = 0; i < x + 1; i++) {
		if (emp[i].pos == old_pos) {
			emp[i].pos = new_pos;
		}
	}
}

void del_pers(Employee* emp, Employee* emp2, int x, int del_pos, int sum) {
	for (int i = 0; i < x + 1; i++) {
		if (emp[i].pos != del_pos) {
			emp2[sum] = emp[i];
			sum++;
		}
	}
}
#endif