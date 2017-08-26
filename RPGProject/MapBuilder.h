#ifndef MAPBUILDER_H

#define MAPBUILDER_H

#include <string>
#include <vector>
#include <map>

#include "Symbol.h"
#include "Space.h"
#include "Map.h"
#include "Builder.h"

class Symbol;
class Space;
class Map;

class MapBuilder
	: public Builder
{
private:
	char _alias_sym;
	int _alias_capacity;
	bool _building_alias;
	std::map <char, std::unique_ptr<Space>> _aliases;
	Map *_m;
	size_t _width;
	std::string _name;
	std::vector<std::string> _rows;
	std::vector<std::vector<std::shared_ptr<Space>>> _data;

	bool _AddRow(std::string row);
	bool _HandleAliasKey(std::string key, std::string value);
	void _CreateAlias();
protected:
	virtual bool Start() override;
	virtual bool Finish() override;
public:
	Map *GetMap();
	MapBuilder();
	~MapBuilder();

	// Inherited via Builder
	virtual bool HandleKey(std::string key, std::string value) override;
};

#endif /* MAPBUILDER_H */

