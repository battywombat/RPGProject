#include <memory>
#include "Space.h"

Space::Space(const Space * obj) : Drawable(obj)
{
	_x = obj->_x;
	_y = obj->_y;
	_capacity = obj->_capacity;
	_p = obj->_p;
	if (_p) {
		_p->SetParent(this);
	}
}

Space::Space(Symbol * sym, int capacity) : Drawable(sym)
{
	_capacity = capacity;
	_x = _y = -1;
	_p = nullptr;
}

Space::Space(Symbol * sym, int _capacity, Portal * p) : Space(sym, _capacity)
{
	_p = p;
	if (_p) {
		_p->SetParent(this);
	}
}

Space::~Space()
{
	for (auto i = _contents.begin(); i != _contents.end(); i++) {
		delete *i;
	}
	if (_p) {
	//	delete _p;
	}
}

void Space::SetCoordinates(int x, int y)
{
	_x = x;
	_y = y;
}

bool Space::CanContain(Drawable * item)
{
	return _capacity > 0;
}

int Space::GetX()
{
	return _x;
}

int Space::GetY()
{
	return _y;
}

void Space::Draw(SDL_Renderer * s, SDL_Rect * dstrect)
{
	auto contents = GetChildren();
	if (contents.size() > 0) {
		auto item = *contents.begin();
		item->Draw(s, dstrect);
	}
	else {
		Drawable::Draw(s, dstrect);
	}
}

std::vector<Drawable *> Space::GetChildren()
{
	auto s = std::vector <Drawable *>();
	for (auto i = _contents.begin(); i != _contents.end(); i++) {
		s.push_back(*i);
	}
	return s;
}

Portal * Space::GetPortal()
{
	return _p;
}

bool Space::RemoveContents(Drawable *item)
{
	for (auto i = _contents.begin(); i != _contents.end(); i++) {
		if (*i == item) {
			_contents.erase(i);
			return true;
		}
	}
	return false;
}

bool Space::AddContents(Drawable *item)
{
	_contents.push_back(item);
	item->SetParent(this);
	return true;
}
