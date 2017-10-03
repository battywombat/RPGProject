#include "World.h"

World::World(std::vector<Map *> data)
	: TreeNode(nullptr), _data(data)
{
	TreeNode *t;
	for (auto i = _data.begin(); i != _data.end(); i++) {
		t = *i;
		t->SetParent(this);
	}
}

bool World::AddCharacter(Character * c, size_t x, size_t y, size_t z)
{
	if (z < 0 || z >= _data.size()) {
		return false;
	}
	return _data[z]->AddCharacter(c, x, y);
}

bool World::AddPlayer(Player * p, size_t x, size_t y, size_t z)
{
	_p = p;
	return this->AddCharacter(p, x, y, z);
}

World::~World()
{
	for (auto i = _data.begin(); i != _data.end(); i++) {
		delete *i;
	}
}

Map * World::GetMap(int z)
{
	if (z < 0 || z >= _data.size()) {
		return nullptr;
	}
	return _data[z];
}

#define WIN_WIDTH 20
#define WIN_HEIGHT 20

void World::Draw(SDL_Renderer * s, SDL_Rect * dstrect)
{
	auto m = dynamic_cast<Map *>(_p->GetParent()->GetParent());
	auto x = _p->GetX();
	auto y = _p->GetY();
	SDL_Rect r;
	r.x = x - WIN_WIDTH < 0 ? 0 : x - WIN_WIDTH;
	r.y = y - WIN_HEIGHT < 0 ? 0 : x - WIN_HEIGHT;
	r.w = dstrect->w - 2;
	r.h = dstrect->h - 2;
	m->Draw(s, &r, dstrect);
}
