#include "Character.h"



Character::Character(Symbol *s)
	: Container(s)
{
}


Character::~Character()
{
}

int Character::GetX()
{
	return 0;
}

int Character::GetY()
{
	return 0;
}

bool Character::CanContain(Item * item)
{
	return true;
}

bool Character::HandleKey(std::string key, std::string value)
{
	return false;
}
