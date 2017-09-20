#ifndef MAP_H

#define MAP_H

#include <string>
#include <vector>

#include <SDL.h>

class Space;
class Character;
class Player;

#include "Space.h"
#include "Player.h"
#include "Character.h"
#include "TreeNode.h"

class Map
	: public TreeNode
{
private:
	std::string _name;
	std::vector<std::vector<Space *>> _data;
public:
	int GetWidth();
	int GetHeight();
	int GetXOf(Space *s);
	int GetYOf(Space *s);
	void DrawBorder(SDL_Renderer *s, SDL_Rect *dstrect);
	void Draw(SDL_Renderer *s, SDL_Rect *src, SDL_Rect *dst);
	std::string GetName();
	Space *GetSpaceAt(size_t x, size_t y);
	bool AddCharacter(Character *c, int x, int y);
	Map(std::string name, std::vector<std::vector<Space *>> data);
	~Map();

};

#endif /* MAP_H */

