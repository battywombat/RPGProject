#ifndef SYMBOL_H

#define SYMBOL_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Symbol
{
private:
	char _sym;
	std::string _fp;
	int _w;
	int _h;
	int _x;
	int _y;
public:
	bool IsChar();
	char GetSymbolChar();
	void Draw(TTF_Font *f, SDL_Surface *s, SDL_Rect *dstrect);
	Symbol(char sym);
	Symbol(std::string fp, int w, int h, int x, int y);
	~Symbol();
};

#endif /* SYMBOL_H */

