#ifndef MAP_H

#define MAP_H

#include <memory>
#include <string>
#include <vector>

#include <SDL.h>
#include <SDL_ttf.h>

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
	void Draw(SDL_Renderer *s, SDL_Rect *dstrect);
	std::string GetName();
	Space *GetSpaceAt(size_t x, size_t y);
	bool PlayerEnterMap(Player *p, int x, int y);
	bool AddCharacter(Character *c, int x, int y);
	Map(std::string name, std::vector<std::vector<Space *>> data);
	~Map();

	// Inherited via TreeNode
	virtual std::vector<TreeNode *> GetChildren() override;
	virtual bool RemoveContents(TreeNode *item) override;
	virtual bool AddContents(TreeNode *item) override;
	virtual bool CanContain(TreeNode *item) override;
};

#endif /* MAP_H */

