#ifndef ITEM_H
#define ITEM_H

#include <SDL.h>

#include "Symbol.h"
#include "TreeNode.h"

/*
	An Item is something that has a physical presence in the game world
*/
class Drawable
	: public TreeNode
{
private:
	Symbol *_sym;
public:
	virtual void Draw(SDL_Renderer *s, SDL_Rect *dstrect);
	Drawable(const Drawable *obj);
	Drawable(Symbol *s);
	~Drawable();
};

#endif /* ITEM_H */
