#ifndef SPACE_H

#define SPACE_H

#include <memory>

#include "Container.h"
#include "Item.h"
#include "Symbol.h"
#include "Map.h"

class Map;
class Symbol;
class Item;

class Space :
	public Container
{
private:
	std::shared_ptr<Map> _m;
	int _x;
	int _y;
	int _capacity;
public:
	Space(const Space *obj);
	Space(Symbol *sym, int _capacity);
	~Space();
	virtual bool CanContain(Item *item);
	virtual int GetX();
	virtual int GetY();
};

#endif /* SPACE_H */

