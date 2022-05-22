#ifndef _BASE_H
#define _BASE_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Base {
private:
	string name;
	Base* parent;
	vector<Base*> children;
	int x = 0;
public:
	Base(string name = "", Base* parent = nullptr);
	string get_name();
	void set_name(string& name);
	Base* get_root();
	void set_root(Base* new_parent);
	Base* find_object(string name);
	void print_tree(string);
	void print_ready_tree(string);
	bool set_ready(int x);
	int get_ready();
};
#endif