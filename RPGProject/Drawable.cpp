#include <memory>

#include <SDL.h>
#include <SDL_ttf.h>

#include "Drawable.h"

Drawable::Drawable(Symbol *s) : TreeNode(nullptr)
{
	_sym = std::shared_ptr<Symbol>(s);
}

Drawable::~Drawable()
{
}

void Drawable::Draw(SDL_Renderer * s, SDL_Rect *dstrect)
{
	_sym->Draw(s, dstrect);
}

Drawable::Drawable(const Drawable * obj) : TreeNode(obj)
{
	_sym = obj->_sym;
}
