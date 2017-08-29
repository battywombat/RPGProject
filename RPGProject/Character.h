#ifndef CHARACTER_H

#define CHARACTER_H
#include <memory>

class Character;
class TreeNode;
class Space;

#include "Drawable.h"
#include "Space.h"

class Character :
	public Drawable
{
private:
	std::shared_ptr<Space> _space;
public:
	Character(Symbol *s);
	~Character();

	virtual bool Move(Direction d);


	// Inherited via Drawable
	virtual std::vector<TreeNode *> GetChildren() override;

	virtual bool RemoveContents(TreeNode *item) override;

	virtual bool AddContents(TreeNode *item) override;

	virtual bool CanContain(TreeNode *item) override;

};

#endif /* CHARACTER_H */

