#include "Character.h"

#include "Map.h"

int Character::GetX()
{
	return dynamic_cast<Space *>(GetParent())->GetX();
}

int Character::GetY()
{
	return dynamic_cast<Space *>(GetParent())->GetY();
}

Character::Character(Symbol *s)
	: Drawable(s)
{
	_parent = nullptr;
}


Character::~Character()
{
}

bool Character::Move(Direction d)
{
	auto s = dynamic_cast<Space *>(GetParent());
	auto m = dynamic_cast<Map *>(s->GetParent());
	int x = s->GetX(), y = s->GetY();
	if (d == Direction::WEST) {
		x -= 1;
	}
	else if (d == Direction::EAST) {
		x += 1;
	}
	else if (d == Direction::NORTH) {
		y -= 1;
	}
	else if (d == Direction::SOUTH) {
		y += 1;
	}
	auto ns = m->GetSpaceAt(x, y);
	if (ns == nullptr || !ns->CanContain(this)) {
		return false;
	}
	s->RemoveContents(this);
	ns->AddContents(this);
	return true;
}

bool Character::TravelPortal()
{
	Space *s = dynamic_cast<Space *>(GetParent());
	if (s == nullptr) {
		return false;
	}
	Portal *p = s->GetPortal();
	if (p == nullptr) {
		return false;
	}
	return p->TravelPortal(this);
}
