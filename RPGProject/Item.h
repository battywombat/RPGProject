#ifndef ITEM_H
#define ITEM_H

#include <SDL.h>
#include <memory>

#include "Symbol.h"

/*
	An Item is something that has a physical presence in the game world
*/
class Item
{
private:
	std::shared_ptr<Symbol> _sym;
public:
	virtual int GetX() = 0;
	virtual int GetY() = 0;
	virtual void DrawSymbol(SDL_Renderer *s, SDL_Rect *dstrect);
	Item(const Item *obj);
	Item(Symbol *s);
	~Item();
};

#endif /* ITEM_H */
