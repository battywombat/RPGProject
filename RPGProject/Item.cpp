#include <memory>

#include <SDL.h>
#include <SDL_ttf.h>
#include "Item.h"

Item::Item(Symbol *s)
{
	_sym = std::shared_ptr<Symbol>(s);
}

Item::~Item()
{
}

void Item::DrawSymbol(SDL_Renderer * s, SDL_Rect *dstrect)
{
	_sym->Draw(s, dstrect);
}

Item::Item(const Item * obj)
{
	_sym = obj->_sym;
}
