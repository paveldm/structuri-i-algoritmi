#ifndef _CL_APPLICATION_H
#define _CL_APPLICATION_H
#include "Base.h"
#include "class1.h"
#include "class2.h"
#include "class3.h"
#include "class4.h"
#include "class5.h"
#include "class6.h"

class cl_application : public Base {
public:
	cl_application(string name = "") : Base(name) {};
	void build_tree_objects();
	int exec_app();
};
#endif