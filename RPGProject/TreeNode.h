#ifndef CONTAINER_H

#define CONTAINER_H

#include <vector>
#include <memory>

#include <SDL.h>

typedef SDL_Rect Rect;

#include "Symbol.h"

/*
A container is an object that holds other objects
*/

enum Direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NORTHEAST,
	NORTHWEST,
	SOUTHEAST,
	SOUTHWEST
};

class TreeNode
{
protected:
	TreeNode *_parent;
public:
	TreeNode();
	TreeNode(const TreeNode *obj);
	virtual ~TreeNode();
	TreeNode *GetParent();
	void SetParent(TreeNode *newParent);
	//virtual bool RemoveContents(TreeNode *item) = 0;
	//virtual bool AddContents(TreeNode *item) = 0;
	//virtual bool CanContain(TreeNode *item) = 0;
	//virtual void Draw(SDL_Renderer *s, SDL_Rect *dstrect) = 0;
};

#endif /* CONTAINER_H */
