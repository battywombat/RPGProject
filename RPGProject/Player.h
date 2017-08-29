#ifndef PLAYER_H

#define PLAYER_H

class Player;
class Character;

#include "Character.h"

class Player :
	public Character
{
public:
	Player();
	~Player();
};

#endif /* PLAYER_H */

