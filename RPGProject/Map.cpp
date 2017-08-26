#include "Map.h"

int Map::GetWidth()
{
	return this->_data[0].size();
}

int Map::GetHeight()
{
	return this->_data.size();
}

int Map::GetXOf(Space *s)
{
	for (size_t i = 0; i < this->_data.size(); i++) {
		for (size_t j = 0; j < this->_data.size(); j++) {
			if (this->_data[i][j].get() == s) {
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
			if (this->_data[i][j].get() == s) {
				return i;
			}
		}
	}
	return -1;
}

void Map::Draw(TTF_Font * f, SDL_Surface * s, SDL_Rect * dstrect)
{
	SDL_Rect current;
	current.x = 0;
	current.y = 0;
	for (size_t i = 0; i < this->_data.size(); i++) {
		for (size_t j = 0; j < this->_data[i].size(); j++) {
			this->_data[i][j]->DrawSymbol(f, s, &current);
			current.x += current.w;
		}
		current.x = 0;
		current.y += current.h;
	}
}

std::string Map::GetName()
{
	return this->_name;
}

std::shared_ptr<Space> Map::GetSpaceAt(size_t x, size_t y)
{
	if (y <= 0 || y >= this->_data.size() || x <= 0 || x >= this->_data[y].size()) {
		return nullptr;
	}
	return this->_data[y][x];
}

Map::Map(std::string name, std::vector<std::vector<std::shared_ptr<Space>>> data)
	: _name(name), _data(data)
{
}

Map::~Map()
{

}
