#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <vector>

#include "SDLRenderer.h"
#include "Space.h"
#include "Map.h"

void SDLRenderer::_RenderFrame()
{
	auto map = this->_state->GetMap();

	SDL_Rect dstrect;

	dstrect.x = 0;
	dstrect.y = 0;
	SDL_GetWindowSize(this->_win, &dstrect.w, &dstrect.h);

	auto canvas = SDL_CreateRGBSurface(0, dstrect.w, dstrect.h, 32, 0, 0, 0, 0);

	map->Draw(this->_font, canvas, &dstrect);

	SDL_Texture *tex = SDL_CreateTextureFromSurface(this->_ren, canvas);

	SDL_RenderClear(this->_ren);
	SDL_RenderCopy(this->_ren, tex, nullptr, &dstrect);
	SDL_RenderPresent(this->_ren);

	SDL_DestroyTexture(tex);
	SDL_FreeSurface(canvas);

}

void SDLRenderer::_Close()
{
	IMG_Quit();
	if (TTF_WasInit()) {
		TTF_Quit();
	}
	if (SDL_WasInit(SDL_INIT_VIDEO)) {
		SDL_Quit();
	}
}

bool SDLRenderer::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	if (TTF_Init() != 0) {
		std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
		return false;
	}

	if (IMG_Init(IMG_INIT_JPG) != IMG_INIT_JPG) {
		std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;
		return false;
	}

	this->_win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (this->_win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}

	this->_ren = SDL_CreateRenderer(this->_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (this->_ren == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}

	this->_font = TTF_OpenFont("art/gomono.ttf", 12);
	if (this->_font == nullptr) {
		std::cout << "SDL_OpenFont Error: " << TTF_GetError() << std::endl;
		return false;
	}

	return true;

}

void SDLRenderer::Start()
{
	SDL_Event ev;
	int quit = 0;

	while (!quit) {
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT) {
				quit = 1;
			}
			else if (ev.type == SDL_KEYDOWN) {
				ev.type = SDL_QUIT;
				SDL_PushEvent(&ev);
			}
		}
		this->_RenderFrame();
	}
}

SDLRenderer::SDLRenderer(GameState *state)
{
	this->_state = std::unique_ptr<GameState>(state);
	this->_win = nullptr;
	this->_ren = nullptr;
	this->_font = nullptr;
}

SDLRenderer::~SDLRenderer()
{
	if (this->_font != nullptr) {
		TTF_CloseFont(this->_font);
	}
	if (this->_ren != nullptr) {
		SDL_DestroyRenderer(this->_ren);
	}
	if (this->_win != nullptr) {
		SDL_DestroyWindow(this->_win);
	}

	this->_Close();
}
