#ifndef _CLASS5_H
#define _CLASS5_H
#include "Base.h"

class class5 : public Base {
public:
	class5(string name, Base* parent) : Base(name, parent) {};
};
#endif