#include "Container.h"
#include <iterator>

Container::Container(const Container * obj)
	: Item(obj)
{
	this->_capacity = obj->_capacity;
	this->_contents = obj->_contents;
}

Container::Container(Symbol *sym) : Item(sym)
{
	this->_contents = std::set<std::shared_ptr<Item>>();
}

Container::~Container()
{
}

std::set<std::shared_ptr<Item>> Container::GetContents()
{
	return this->_contents;
}

bool Container::RemoveContents(std::shared_ptr<Item> item)
{
	std::set<std::shared_ptr<Item>>::iterator it;
	if ((it = this->_contents.find(item)) == this->_contents.end()) {
		return false;
	}
	this->_contents.erase(it);
	return true;
}

bool Container::AddContents(Item * item)
{
	this->_contents.emplace(item);
	return true;
}
