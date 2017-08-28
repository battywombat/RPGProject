#include "Map.h"
#include "Graphics.h"

int Map::GetWidth()
{
	return _data[0].size();
}

int Map::GetHeight()
{
	return _data.size();
}

int Map::GetXOf(Space *s)
{
	for (size_t i = 0; i < _data.size(); i++) {
		for (size_t j = 0; j < _data.size(); j++) {
			if (_data[i][j].get() == s) {
				return j;
			}
		}
	}
	return -1;
}

int Map::GetYOf(Space *s)
{
	for (size_t i = 0; i < this->_data.size(); i++) {
		for (size_t j = 0; j < this->_data.size(); j++) {
			if (_data[i][j].get() == s) {
				return i;
			}
		}
	}
	return -1;
}

void Map::Draw(SDL_Renderer * s, SDL_Rect * dstrect)
{
	SDL_Rect current;
	Graphics::GetSprite(0, &current);
	current.x = dstrect->x;
	current.y = dstrect->y;
	for (size_t i = 0; i < dstrect->h / current.h && i < _data.size(); i++) {
		for (size_t j = 0; j < dstrect->w / current.w && j < _data[i].size(); j++) {
			_data[i][j]->DrawSymbol(s, &current);
			current.x += current.w;
		}
		current.x = dstrect->x;
		current.y += current.h;
	}
}

std::string Map::GetName()
{
	return _name;
}

std::shared_ptr<Space> Map::GetSpaceAt(size_t x, size_t y)
{
	if (y <= 0 || y >= _data.size() || x <= 0 || x >= _data[y].size()) {
		return nullptr;
	}
	return _data[y][x];
}

Map::Map(std::string name, std::vector<std::vector<std::shared_ptr<Space>>> data)
	: _name(name), _data(data)
{
}

Map::~Map()
{
}
