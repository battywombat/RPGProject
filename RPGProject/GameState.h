#ifndef GAMESTATE_H

#define GAMESTATE_H

#include "Map.h"

class GameState
{
private:
	Map *_map;
public:
	Map *GetMap();
	GameState();
	~GameState();
};

#endif /* GAMESTATE_H */

