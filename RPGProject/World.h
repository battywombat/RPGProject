#ifndef WORLD_H

#define WORLD_H

#include <SDL.h>
#include <vector>

#include "Character.h"
#include "TreeNode.h"
#include "Map.h"

class World :
	public TreeNode
{
private:
	std::vector<Map *> _data;
	Player *_p;
	Rect viewport;
public:
	World(std::vector<Map *> data);
	bool AddCharacter(Character *c, size_t x, size_t y, size_t z);
	bool AddPlayer(Player *p, size_t x, size_t y, size_t z);
	~World();
	Map *GetMap(int z);

	// Inherited via TreeNode
	virtual void Draw(SDL_Renderer * s, SDL_Rect * dstrect);
};

#endif /* WORLD_H */

