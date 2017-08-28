#ifndef CHARACTERBUILDER_H

#define CHARACTERBUILDER_H
#include "Builder.h"
#include "Character.h"
#include "Symbol.h"

class CharacterBuilder :
	public Builder
{
private:
	bool _parsing_sym;
	Character *_c;
	int _symnum;
	int _fg[3];
	int _bg[3];

	bool _HandleSymKey(std::string key, std::string value);
public:
	CharacterBuilder();
	~CharacterBuilder();
	Character *GetCharacter();

	// Inherited via Builder
	virtual bool HandleKey(std::string key, std::string value) override;
	virtual bool Start() override;
	virtual bool Finish() override;
};

#endif /* CHARACTERBUILDER_H */

