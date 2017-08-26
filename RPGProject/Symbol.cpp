#include <SDL.h>
#include <SDL_ttf.h>
#include "Symbol.h"




bool Symbol::IsChar()
{
	return this->_sym != -1;
}

char Symbol::GetSymbolChar()
{
	return this->_sym;
}

void Symbol::Draw(TTF_Font *f, SDL_Surface * s, SDL_Rect *dstrect)
{
	std::string letter(1, this->_sym);
	SDL_Color white = { 255, 255, 255 };
	SDL_Surface *renderSurface = TTF_RenderText_Solid(f, letter.c_str(), white);
	SDL_BlitSurface(renderSurface, nullptr, s, dstrect);
	TTF_SizeText(f, letter.c_str(), &dstrect->w, &dstrect->h);
	SDL_FreeSurface(renderSurface);
}

Symbol::Symbol(char sym) : _sym(sym)
{
}

Symbol::Symbol(std::string fp, int w, int h, int x, int y) : _fp(fp), _w(w), _h(h), _x(x), _y(y)
{
	this->_sym = -1;
}

Symbol::~Symbol()
{
}
