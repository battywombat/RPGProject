#include <memory>
#include "Space.h"

Space::Space(const Space * obj) : Container(obj)
{
	_x = obj->_x;
	_y = obj->_y;
	_capacity = obj->_capacity;
	_m = obj->_m;
}

Space::Space(Symbol * sym, int capacity) : Container(sym)
{
	_capacity = capacity;
	_x = _y = -1;
}

Space::~Space()
{
}

bool Space::CanContain(Item * item)
{
	return _capacity > 0;
}

int Space::GetX()
{
	return _x == -1 ? _x = _m->GetXOf(this) : _x;
}

int Space::GetY()
{
	return _y == -1 ? _y = _m->GetYOf(this) : _y;
}

void Space::DrawSymbol(SDL_Renderer * s, SDL_Rect * dstrect)
{
	auto contents = GetContents();
	if (GetContents().size() > 0) {
		auto item = *contents.begin();
		item->DrawSymbol(s, dstrect);
	}
	else {
		Item::DrawSymbol(s, dstrect);
	}
}
