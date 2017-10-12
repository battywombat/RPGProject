#ifndef GAMESTATE_H

#define GAMESTATE_H

#include "Map.h"
#include "Player.h"
#include "World.h"
#include "Space.h"

class GameState
{
private:
	World *_world;
	Player *_p;
	enum Direction _CursorDirection;
	void _DrawCursor(SDL_Renderer *s);
public:
	Space *GetSquarePointedByCursor();
	World *GetWorld();
	Player *GetPlayer();
	GameState();
	void Draw(SDL_Renderer *s, SDL_Rect *dim);
	void SetCursorDirection(Direction d);
	~GameState();
};

#endif /* GAMESTATE_H */

