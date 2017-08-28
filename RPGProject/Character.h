#ifndef CHARACTER_H

#define CHARACTER_H
#include "Container.h"
#include "Builder.h"
class Character :
	public Container, Builder
{
public:
	Character(Symbol *s);
	~Character();

	// Inherited via Container
	virtual int GetX() override;
	virtual int GetY() override;
	virtual bool CanContain(Item * item) override;

	// Inherited via Builder
	virtual bool HandleKey(std::string key, std::string value) override;
};

#endif /* CHARACTER_H */

