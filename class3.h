#ifndef _CLASS3_H
#define _CLASS3_H
#include "Base.h"

class class3 : public Base {
public:
	class3(string name, Base* parent) : Base(name, parent) {};
};
#endif