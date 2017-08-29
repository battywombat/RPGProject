#ifndef CONTAINER_H

#define CONTAINER_H

#include <vector>
#include <memory>

#include "Symbol.h"

/*
A container is an object that holds other objects
*/

enum Direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

struct TreeIndex
{
	int x;
	int y;
	int z;
};

class TreeNode
{
protected:
	TreeNode *_parent;
public:
	TreeNode(const TreeNode *obj);
	~TreeNode();
	TreeNode *GetParent();
	void SetParent(TreeNode *newParent);
	virtual std::vector<TreeNode *> GetChildren() = 0;
	virtual bool RemoveContents(TreeNode *item) = 0;
	virtual bool AddContents(TreeNode *item) = 0;
	virtual bool CanContain(TreeNode *item) = 0;
	virtual void Draw(SDL_Renderer *s, SDL_Rect *dstrect) = 0;
};

#endif /* CONTAINER_H */
