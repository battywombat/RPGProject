#include "Portal.h"
#include "Space.h"
#include "World.h"


Portal::Portal(int x, int y) 
	: _x(x), _y(y), _z(-1)
{
}

Portal::Portal(int x, int y, int z)
	: _x(x), _y(y), _z(z)
{
}

bool Portal::TravelPortal(Character * c)
{
	Space *src = static_cast<Space *>(c->GetParent());
	Space *dst = GetDest();
	src->RemoveContents(c);
	dst->AddContents(c);

	return true;
}

Space * Portal::GetDest()
{
	World *w = nullptr;
	TreeNode *t = GetParent();
	while (t != nullptr && (w = dynamic_cast<World *>(t)) == nullptr) {
		t = t->GetParent();
	}
	if (!t || !w) {
		return nullptr;
	}
	Map *m = w->GetMap(_z);
	if (!m) {
		return nullptr;
	}
	return m->GetSpaceAt(_x, _y);
}

Portal::~Portal()
{
}

void Portal::Draw(SDL_Renderer * s, SDL_Rect * dstrect)
{
}
