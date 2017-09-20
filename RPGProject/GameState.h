#ifndef GAMESTATE_H

#define GAMESTATE_H

#include "Map.h"
#include "Player.h"
#include "World.h"

class GameState
{
private:
	World *_world;
	Player *_p;
public:
	World *GetWorld();
	Player *GetPlayer();
	GameState();
	~GameState();
};

#endif /* GAMESTATE_H */

