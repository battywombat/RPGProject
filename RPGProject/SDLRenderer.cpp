#include <iostream>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "SDLRenderer.h"
#include "Space.h"
#include "Map.h"
#include "Graphics.h"

void SDLRenderer::_RenderFrame()
{
	auto world = _state->GetWorld();

	SDL_Rect win_dim;

	win_dim.x = win_dim.y = 0;
	SDL_GetWindowSize(_win, &win_dim.w, &win_dim.h);

	SDL_RenderClear(_ren);

	_state->Draw(_ren, &win_dim);

	SDL_SetRenderDrawColor(_ren, 0, 0, 0, 0);

	SDL_RenderPresent(_ren);
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

void SDLRenderer::_HandleKey(SDL_KeyboardEvent * ev)
{
	switch (ev->keysym.sym) {
	case SDLK_LEFT:
		_state->GetPlayer()->Move(Direction::WEST);
		break;
	case SDLK_RIGHT:
		_state->GetPlayer()->Move(Direction::EAST);
		break;
	case SDLK_UP:
		_state->GetPlayer()->Move(Direction::NORTH);
		break;
	case SDLK_DOWN:
		_state->GetPlayer()->Move(Direction::SOUTH);
		break;
	case '.':
		_state->GetPlayer()->TravelPortal();
		break;
	case 'w':
		_state->SetCursorDirection(Direction::NORTH);
		break;
	case 'a':
		_state->SetCursorDirection(Direction::WEST);
		break;
	case 's':
		_state->SetCursorDirection(Direction::SOUTH);
		break;
	case 'd':
		_state->SetCursorDirection(Direction::EAST);
		break;
	case 'q':
		_state->SetCursorDirection(Direction::NORTHWEST);
		break;
	case 'e':
		_state->SetCursorDirection(Direction::NORTHEAST);
		break;
	case 'z':
		_state->SetCursorDirection(Direction::SOUTHWEST);
		break;
	case 'c':
		_state->SetCursorDirection(Direction::SOUTHEAST);
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

	_win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (_win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}

	_ren = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_ren == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}

	_font = TTF_OpenFont("art/gomono.ttf", 13);
	if (_font == nullptr) {
		std::cout << "SDL_OpenFont Error: " << TTF_GetError() << std::endl;
		return false;
	}

	Graphics::Init(_ren, "config/graphics.txt");

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
				_HandleKey(&ev.key);
			}
		}
		_RenderFrame();
	}
}

SDLRenderer::SDLRenderer(GameState *state) : _win(nullptr), _ren(nullptr), _font(nullptr)
{
	_state = std::unique_ptr<GameState>(state);
}

SDLRenderer::~SDLRenderer()
{
	if (_font != nullptr) {
		TTF_CloseFont(_font);
	}
	if (_ren != nullptr) {
		SDL_DestroyRenderer(_ren);
	}
	if (_win != nullptr) {
		SDL_DestroyWindow(_win);
	}

	_Close();
}
