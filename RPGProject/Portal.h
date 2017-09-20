#ifndef PORTAL_H

#define PORTAL_H

#include "Character.h"
#include "Symbol.h"
#include "TreeNode.h"

class Character;
class Space;


class Portal
	: public TreeNode
{
private:
	int _x;
	int _y;
	int _z;

public:
	Portal(int x, int y);
	Portal(int x, int y, int z);
	bool TravelPortal(Character *c);
	Space *GetDest();
	~Portal();

	// Inherited via TreeNode
	virtual void Draw(SDL_Renderer * s, SDL_Rect * dstrect);
};

#endif /* PORTAL_H */

