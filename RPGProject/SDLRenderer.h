#ifndef SDLRENDERER_H

#define SDLRENDERER_H

#include <memory>

#include <SDL.h>
#include <SDL_ttf.h>

#include "GameState.h"

class SDLRenderer
{
private:
	const static int map_width = 32;
	const static int map_height = 32;

	SDL_Window *_win;
	SDL_Renderer *_ren;
	TTF_Font *_font;
	std::unique_ptr<GameState> _state;

	void _RenderFrame();
	void _Close();
	void _HandleKey(SDL_KeyboardEvent *ev);
public:
	bool Init();
	void Start();
	SDLRenderer(GameState *state);
	~SDLRenderer();
};

#endif /* SDLRENDERER_H */

