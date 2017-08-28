#ifndef SYMBOL_H

#define SYMBOL_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Symbol
{
private:
	uint8_t _bg[3];
	uint8_t _fg[3];
	int _spritenum;
public:
	void Draw(SDL_Renderer *s, SDL_Rect *dstrect);
	Symbol(int _spritenum);
	Symbol(int _spritenum, int fgr, int fgg, int fgb);
	Symbol(int _spritenum, int fgr, int fgg, int fgb, int bgr, int bgg, int bgb);
	~Symbol();
};

#endif /* SYMBOL_H */

