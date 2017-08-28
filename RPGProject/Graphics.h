#ifndef GRAPHICS_H

#define GRAPHICS_H

#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "Builder.h"

class Graphics
	: public Builder
{
private:
	SDL_Renderer *_ren;
	static Graphics *_instance;
	int _sheet_width;
	int _sheet_height;
public:
	SDL_Texture *Sheet;
	int Width;
	int Height;
	static void Init(SDL_Renderer *ren, std::string fp);
	static SDL_Texture *GetSprite(int spritenum, SDL_Rect *dim);
	Graphics(SDL_Renderer *r, std::string fp);
	~Graphics();

	// Inherited via Builder
	virtual bool HandleKey(std::string key, std::string value) override;
};

#endif /* GRAPHICS_H */

