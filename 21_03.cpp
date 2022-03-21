#include <iostream>
#include <vector>
using namespace std;
//Строка Карточки читателя: номер чит билета, название книги, автор, дата выдачи и дата возврата
//Дата: номер дня, номер месяца, год
struct date {
	int d, m, y;
};
struct LileKarty {
	int number;
	char NameBook[20];
	char Author[30];
	date date1; //дата выдачи
	date date2; //дата возврата
};
void inputRec(LileKarty &L) {
	cout << "number = "; cin >> L.number;
	cout << "Author = "; cin >> L.Author;
	cout << "NameBook = "; cin >> L.NameBook;
	cout << "data 1 3 chisla: d m y"; cin >> L.date1.d >> L.date1.m >> L.date1.y;
	cout << "data 2 3 chisla: d m y"; cin >> L.date2.d >> L.date2.m >> L.date2.y;
}
void outRec(LileKarty L) {
	cout << "\n" << "\n";
	cout << "number = "; cout << L.number << "\n";
	cout << "Author = ";  cout << L.Author << "\n";
	cout << "NameBook = ";  cout << L.NameBook << "\n";
	cout << "data 1 3 chisla: d m y";  cout << L.date1.d << L.date1.m << L.date1.y << "\n";
	cout << "data 2 3 chisla: d m y";  cout << L.date2.d << L.date2.m << L.date2.y << "\n";

}
int main() {
	LileKarty LK = { 0,"","",{0,0,0},{0,0,0} };
	inputRec(LK);
	outRec(LK);
	LileKarty LK1 = LK;
	outRec(LK1);
	LileKarty* BookMan = new LileKarty[2];
	vector<LileKarty> V(2);
}