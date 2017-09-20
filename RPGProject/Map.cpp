#include "Map.h"
#include "Graphics.h"
#include "World.h"

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
			if (_data[i][j] == s) {
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
			if (_data[i][j] == s) {
				return i;
			}
		}
	}
	return -1;
}

void Map::DrawBorder(SDL_Renderer * s, SDL_Rect * dstrect)
{
	SDL_Rect square_dim;
	Graphics::GetSprite(0, &square_dim);
	SDL_Rect frames[4];
	SDL_SetRenderDrawColor(s, 255, 255, 255, 0);

	// top
	frames[0].x = dstrect->x;
	frames[0].y = dstrect->y;
	frames[0].w = dstrect->w;
	frames[0].h = square_dim.h + (dstrect->h % square_dim.h) / 2;

	// left
	frames[1].x = dstrect->x;
	frames[1].y = dstrect->y;
	frames[1].w = square_dim.w * 2 + dstrect->w % square_dim.w;
	frames[1].h = dstrect->h;

	// bottom
	frames[2].x = dstrect->x;
	frames[2].y = dstrect->y + dstrect->h - frames[0].h;
	frames[2].w = dstrect->w;
	frames[2].h = frames[0].h;

	// right
	frames[3].x = dstrect->x + dstrect->w - frames[1].w;
	frames[3].y = dstrect->y;
	frames[3].w = frames[1].w;
	frames[3].h = dstrect->h;

	SDL_RenderFillRects(s, frames, 4);
	dstrect->x += frames[1].w;
	dstrect->w -= frames[1].w * 2;
	dstrect->y += frames[0].h;
	dstrect->h -= frames[0].h * 2;
}

void Map::Draw(SDL_Renderer * s, SDL_Rect *src, SDL_Rect * dst)
{
	DrawBorder(s, dst);
	SDL_Rect current;
	Graphics::GetSprite(0, &current);
	current.x = dst->x;
	current.y = dst->y;
	for (size_t i = 0; current.y < dst->h + dst->y && i < _data.size(); i++) {
		for (size_t j = 0; current.x < dst->w + dst->x && j < _data[i].size(); j++) {
			_data[i][j]->Draw(s, &current);
			current.x += current.w;
		}
		current.x = dst->x;
		current.y += current.h;
	}
}

std::string Map::GetName()
{
	return _name;
}

Space *Map::GetSpaceAt(size_t x, size_t y)
{
	if (y <= 0 || y >= _data.size() || x <= 0 || x >= _data[y].size()) {
		return nullptr;
	}
	return _data[y][x];
}

bool Map::AddCharacter(Character *c, int x, int y)
{
	auto sp = GetSpaceAt(x, y);
	if (sp == nullptr || !sp->CanContain(c)) {
		return false;
	}
	sp->AddContents(c);
	return false;
}

Map::Map(std::string name, std::vector<std::vector<Space *>> data)
	: TreeNode(nullptr), _name(name), _data(data)
{
	for (size_t i = 0; i < _data.size(); i++) {
		for (size_t j = 0; j < _data[i].size(); j++) {
			_data[i][j]->SetCoordinates(j, i);
			_data[i][j]->SetParent(this);
		}
	}
}

Map::~Map()
{
	for (auto i = _data.begin(); i != _data.end(); i++) {
		for (auto j = i->begin(); j != i->end(); j++) {
			delete *j;
		}
	}
}
