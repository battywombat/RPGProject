#include <memory>
#include "Space.h"

Space::Space(const Space * obj) : Container(obj)
{
	this->_x = obj->_x;
	this->_y = obj->_y;
	this->_capacity = obj->_capacity;
	this->_m = obj->_m;
}

Space::Space(Symbol * sym, int capacity) : Container(sym)
{
	this->_capacity = capacity;
	this->_x = this->_y = -1;
}

Space::~Space()
{
}

bool Space::CanContain(Item * item)
{
	return this->_capacity > 0;
}

int Space::GetX()
{
	return this->_x == -1 ? this->_x = this->_m->GetXOf(this) : this->_x;
}

int Space::GetY()
{
	return this->_y == -1 ? this->_y = this->_m->GetYOf(this) : this->_y;
}
