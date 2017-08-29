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

void Map::Draw(SDL_Renderer * s, SDL_Rect * dstrect)
{
	SDL_Rect current;
	Graphics::GetSprite(0, &current);
	current.x = dstrect->x;
	current.y = dstrect->y;
	for (size_t i = 0; i < dstrect->h / current.h && i < _data.size(); i++) {
		for (size_t j = 0; j < dstrect->w / current.w && j < _data[i].size(); j++) {
			_data[i][j]->Draw(s, &current);
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

Space *Map::GetSpaceAt(size_t x, size_t y)
{
	if (y <= 0 || y >= _data.size() || x <= 0 || x >= _data[y].size()) {
		return nullptr;
	}
	return _data[y][x];
}

bool Map::PlayerEnterMap(Player *p, int x, int y)
{
	return AddCharacter(p, x, y);
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

std::vector<TreeNode *> Map::GetChildren()
{
	return std::vector<TreeNode *>();
}

bool Map::RemoveContents(TreeNode *item)
{
	return false;
}

bool Map::AddContents(TreeNode *item)
{
	return false;
}

bool Map::CanContain(TreeNode *item)
{
	return false;
}
