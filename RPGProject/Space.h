#ifndef SPACE_H

#define SPACE_H

#include <memory>

#include "Drawable.h"
#include "Symbol.h"

class Drawable;
class TreeNode;
class Symbol;

class Space :
	public Drawable
{
private:
	int _x;
	int _y;
	int _capacity;
	std::vector <Drawable *> _contents;
public:
	Space(const Space *obj);
	Space(Symbol *sym, int _capacity);
	~Space();
	virtual void SetCoordinates(int x, int y);
	virtual bool CanContain(Drawable *item);
	virtual int GetX();
	virtual int GetY();
	virtual void Draw(SDL_Renderer *s, SDL_Rect *dstrect) override;

	// Inherited via Drawable
	virtual std::vector<TreeNode *> GetChildren() override;
	virtual bool RemoveContents(TreeNode *item) override;
	virtual bool AddContents(TreeNode *item) override;
	virtual bool CanContain(TreeNode *item) override;
};

#endif /* SPACE_H */

