#include "Container.h"
#include <iterator>

Container::Container(const Container * obj)
	: Item(obj)
{
	_capacity = obj->_capacity;
	_contents = obj->_contents;
}

Container::Container(Symbol *sym) : Item(sym)
{
	_contents = std::set<std::shared_ptr<Item>>();
}

Container::~Container()
{
}

std::set<std::shared_ptr<Item>> Container::GetContents()
{
	return _contents;
}

bool Container::RemoveContents(std::shared_ptr<Item> item)
{
	std::set<std::shared_ptr<Item>>::iterator it;
	if ((it = _contents.find(item)) == _contents.end()) {
		return false;
	}
	_contents.erase(it);
	return true;
}

bool Container::AddContents(Item * item)
{
	_contents.emplace(item);
	return true;
}
