#ifndef GAMESTATE_H

#define GAMESTATE_H

#include <memory>

#include "Map.h"
#include "Player.h"

class GameState
{
private:
	Map *_map;
	Player *_p;
public:
	Map *GetMap();
	Player *GetPlayer();
	GameState();
	~GameState();
};

#endif /* GAMESTATE_H */

