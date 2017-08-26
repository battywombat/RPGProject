#ifndef CONTAINER_H

#define CONTAINER_H

#include <set>
#include <memory>

#include "Item.h"
#include "Symbol.h"

/*
A container is an object that holds other objects
*/

class Item;

class Container
	: public Item
{
private:
	int _capacity;
	std::set<std::shared_ptr<Item>> _contents;
public:
	Container(const Container *obj);
	Container(Symbol *sym);
	~Container();
	virtual std::set<std::shared_ptr<Item>> GetContents();
	virtual bool RemoveContents(std::shared_ptr<Item> item);
	virtual bool AddContents(Item *item);
	virtual bool CanContain(Item *item) = 0;
};

#endif /* CONTAINER_H */
