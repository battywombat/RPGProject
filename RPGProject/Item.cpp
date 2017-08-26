#include <memory>

#include <SDL.h>
#include <SDL_ttf.h>
#include "Item.h"

Item::Item(Symbol *s)
{
	this->_sym = std::shared_ptr<Symbol>(s);
}

Item::~Item()
{
}

void Item::DrawSymbol(TTF_Font *f, SDL_Surface * s, SDL_Rect *dstrect)
{
	this->_sym->Draw(f, s, dstrect);
}

Item::Item(const Item * obj)
{
	this->_sym = obj->_sym;
}
