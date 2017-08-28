#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include "Symbol.h"
#include "Graphics.h"

void Symbol::Draw(SDL_Renderer * s, SDL_Rect *dstrect)
{
	SDL_Rect srcrect;
	SDL_Texture *t = Graphics::GetSprite(this->_spritenum, &srcrect);
	SDL_SetRenderDrawColor(s, _bg[0], _bg[1], _bg[2], 0);
	SDL_RenderFillRect(s, dstrect);
	SDL_SetTextureColorMod(t, _fg[0], _fg[1], _fg[2]);
	SDL_RenderCopy(s, t, &srcrect, dstrect);
}

Symbol::Symbol(int spritenum) : _spritenum(spritenum)
{
	_bg[0] = _bg[1] = _bg[2] = 0;
	_fg[0] = _fg[1] = _fg[2] = 255;
}

Symbol::Symbol(int _spritenum, int fgr, int fgg, int fgb) : Symbol(_spritenum)
{
	_fg[0] = fgr;
	_fg[1] = fgg;
	_fg[2] = fgb;
	_bg[0] = _bg[1] = _bg[2] = 0;
}

Symbol::Symbol(int _spritenum, int fgr, int fgg, int fgb, int bgr, int bgg, int bgb) : Symbol(_spritenum, fgr, fgb, fgb)
{
	_bg[0] = bgr;
	_bg[1] = bgg;
	_bg[2] = bgb;
}

Symbol::~Symbol()
{
}
