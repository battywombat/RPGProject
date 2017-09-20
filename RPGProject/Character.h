#ifndef CHARACTER_H

#define CHARACTER_H

#include "Drawable.h"
#include "Space.h"

class Character;
class TreeNode;
class Space;

class Character :
	public Drawable
{
public:
	int GetX();
	int GetY();
	Character(Symbol *s);
	~Character();

	virtual bool Move(Direction d);
	virtual bool TravelPortal();

};

#endif /* CHARACTER_H */

