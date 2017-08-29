#include <memory>
#include "Space.h"

Space::Space(const Space * obj) : Drawable(obj)
{
	_x = obj->_x;
	_y = obj->_y;
	_capacity = obj->_capacity;
}

Space::Space(Symbol * sym, int capacity) : Drawable(sym)
{
	_capacity = capacity;
	_x = _y = -1;
}

Space::~Space()
{
	for (auto i = _contents.begin(); i != _contents.end(); i++) {
		delete *i;
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

std::vector<TreeNode *> Space::GetChildren()
{
	auto s = std::vector <TreeNode *>();
	for (auto i = _contents.begin(); i != _contents.end(); i++) {
		s.push_back(*i);
	}
	return s;
}

bool Space::RemoveContents(TreeNode *item)
{
	for (auto i = _contents.begin(); i != _contents.end(); i++) {
		if (*i == item) {
			_contents.erase(i);
			break;
		}
	}
	return false;
}

bool Space::AddContents(TreeNode *item)
{
	auto i = dynamic_cast<Drawable *>(item);
	if (i == nullptr) {
		return false;
	}
	_contents.push_back(i);
	i->SetParent(this);
	return true;
}

bool Space::CanContain(TreeNode *item)
{
	auto i = dynamic_cast<Drawable *>(item);
	return i != nullptr;
}
