#include "cl_application.h"

void cl_application::build_tree_objects() {
	string parent_name, name;
	Base* parent, * child;
	cin >> parent_name;
	set_name(parent_name);
	int num;
	while (true) {
		cin >> parent_name;
		if (parent_name == "endtree")
			break;
		cin >> name >> num;
		parent = find_object(parent_name);
		switch (num)
		{
		case(2):
			child = new class1(name, parent);
			break;
		case(3):
			child = new class2(name, parent);
			break;
		case(4):
			child = new class3(name, parent);
			break;
		case(5):
			child = new class4(name, parent);
			break;
		case(6):
			child = new class5(name, parent);
			break;
		case(7):
			child = new class6(name, parent);
			break;
		}
	}
}

int cl_application::exec_app() {
	cout << "Object tree";
	print_tree("");
	string object_name;
	int new_state;
	while (cin >> object_name >> new_state)
	{
		//if (object_name == "end") {
		//	break;
		//}
		Base* cl = find_object(object_name);
		cl->set_ready(new_state);
	}
	cout << endl << "The tree of objects and their readiness";
	print_ready_tree("");
	return 0;
}
