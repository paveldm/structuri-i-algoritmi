#ifndef _CLASS2_H
#define _CLASS2_H
#include "Base.h"

class class2 : public Base {
public:
	class2(string name, Base* parent) : Base(name, parent) {};
};
#endif