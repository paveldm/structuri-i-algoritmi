#ifndef _CLASS1_H
#define _CLASS1_H
#include "Base.h"

class class1 : public Base {
public:
	class1(string name, Base* parent) : Base(name, parent) {};
};
#endif