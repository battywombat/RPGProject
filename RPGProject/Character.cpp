#include "Character.h"

#include "Map.h"

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

std::vector<TreeNode *> Character::GetChildren()
{
	return std::vector<TreeNode *>();
}

bool Character::RemoveContents(TreeNode *item)
{
	return false;
}

bool Character::AddContents(TreeNode *item)
{
	return false;
}

bool Character::CanContain(TreeNode *item)
{
	return false;
}
