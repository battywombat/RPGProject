#ifndef SPACE_H

#define SPACE_H

#include <memory>

#include "Drawable.h"
#include "Symbol.h"
#include "Portal.h"

class Drawable;
class TreeNode;
class Symbol;
class Portal;

class Space :
	public Drawable
{
private:
	int _x;
	int _y;
	int _capacity;
	std::vector <Drawable *> _contents;
	Portal *_p;
public:
	Space(const Space *obj);
	Space(Symbol *sym, int _capacity);
	Space(Symbol *sym, int _capacity, Portal *p);
	~Space();
	virtual void SetCoordinates(int x, int y);
	virtual int GetX();
	virtual int GetY();
	virtual void Draw(SDL_Renderer *s, SDL_Rect *dstrect) override;
	virtual std::vector<Drawable *> GetChildren();
	Portal *GetPortal();

	// Inherited via Drawable
	virtual bool RemoveContents(Drawable *item);
	virtual bool AddContents(Drawable *item);
	virtual bool CanContain(Drawable *item);
};

#endif /* SPACE_H */

