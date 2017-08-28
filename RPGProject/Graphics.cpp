#include "Graphics.h"

Graphics *Graphics::_instance = nullptr;

void Graphics::Init(SDL_Renderer * ren, std::string fp)
{
	Graphics::_instance = new Graphics(ren, fp);
}

SDL_Texture * Graphics::GetSprite(int spritenum, SDL_Rect * dim)
{
	dim->x = (spritenum % Graphics::_instance->_sheet_width) * Graphics::_instance->Width;
	dim->y = (spritenum / Graphics::_instance->_sheet_width) * Graphics::_instance->Height;
	dim->w = Graphics::_instance->Width;
	dim->h = Graphics::_instance->Height;
	return Graphics::_instance->Sheet;
}

Graphics::Graphics(SDL_Renderer *ren, std::string fp)
{
	_ren = ren;
	ParseFile(fp);
}


Graphics::~Graphics()
{
	SDL_DestroyTexture(this->Sheet);
}

bool Graphics::HandleKey(std::string key, std::string value)
{
	if (key == "FILE") {
		SDL_Surface *s = IMG_Load(value.c_str());
		if (s == nullptr) {
			return false;
		}
		SDL_SetColorKey(s, SDL_TRUE, 0);
		Sheet = SDL_CreateTextureFromSurface(this->_ren, s);
		SDL_FreeSurface(s);
		if (Sheet == nullptr) {
			return false;
		}
	}
	else if (key == "SPRITE_WIDTH") {
		Width = stoi(value);
	}
	else if (key == "SPRITE_HEIGHT") {
		Height = stoi(value);
	}
	else if (key == "SHEET_WIDTH") {
		_sheet_width = stoi(value);
	}
	else if (key == "SHEET_HEIGHT") {
		_sheet_height = stoi(value);
	}
	return true;
}
