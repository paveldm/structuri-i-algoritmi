#include "Base.h"

Base::Base(string name, Base* parent) {
	this->name = name;
	this->parent = parent;
	if (parent)
		parent->children.push_back(this);
	return;
}

void Base::set_name(string& name) {
	this->name = name;
	return;
}

string Base::get_name() {
	return name;
}

void Base::set_root(Base* new_parent) {
	if (parent)
		for (int i = 0; i < parent->children.size(); i++)
			if (parent->children[i] == this)
				parent->children.erase(parent->children.begin() + i);
	parent = new_parent;
	if (new_parent)
		new_parent->children.push_back(this);
	return;
}

Base* Base::get_root() {
	return this->parent;
}

bool Base::set_ready(int x) {
	if (!x) {
		if ((parent and parent->get_ready() == 0) || get_ready() == 0)
			return true;
		else
		{
			for (Base* child : children)
				child->set_ready(0);
			this->x = 0;
			return true;
		}
	}
	else {
		if (parent and parent->get_ready() == 0)
			return false;
		else
		{
			this->x = x;
			return true;
		}
	}
}

int Base::get_ready() {
	return this->x;
}

void Base::print_tree(string space) {
	cout << endl << space << get_name();
	for (auto child : children)
		child->print_tree(space + " ");
}

void Base::print_ready_tree(string space) {
	cout << endl << space << get_name();
	if (!x)
		cout << " is not ready";
	else
		cout << " is ready";
	for (Base* child : children)
		child->print_ready_tree(space + " ");
}

Base* Base::find_object(string name) {
	if (this->name == name)
		return this;
	else
	{
		for (Base* child : children)
		{
			Base* res = child->find_object(name);
			if (res)
				return res;
		}
		return nullptr;
	}
}