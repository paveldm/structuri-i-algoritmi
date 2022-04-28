#include "4.h"
const int N = 100;

struct Position {
	int code;
	string name;
};

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Position pos[5];
	pos[0].code = 10;
	pos[0].name = "Директор";

	pos[1].code = 11;
	pos[1].name = "Стажер";

	pos[2].code = 12;
	pos[2].name = "Менеджер";

	pos[3].code = 13;
	pos[3].name = "Аналитик";

	pos[4].code = 14;
	pos[4].name = "Юрист";

	Employee emp[N];
	Employee emp2[N];
	int x;
	cout << "Введите количество сотрудников: ";
	cin >> x;
	cout << "\n";
	input_pers(emp, x);
	add_pers(emp, x);
	sort(emp, x);
	output_pers(emp, x);
	int old_pos, new_pos;
	cout << "\nВведите код старой и новой должности: "; cin >> old_pos >> new_pos;
	replace_pos(emp, x, old_pos, new_pos);
	output_pers(emp, x);
	int del_pos, size_emp2 = 0;
	cout << "Введите код должности, сотрудников которой нужно удалить (от 10 до 14): "; cin >> del_pos;
	del_pers(emp, emp2, x, del_pos, size_emp2);
	output_pers(emp2, size_emp2 + 1);
}