#ifndef MAP_H

#define MAP_H

#include <memory>
#include <string>
#include <vector>

#include <SDL.h>
#include <SDL_ttf.h>

#include "Space.h"

class Space;

class Map
{
private:
	std::string _name;
	std::vector<std::vector<std::shared_ptr<Space>>> _data;
public:
	int GetWidth();
	int GetHeight();
	int GetXOf(Space *s);
	int GetYOf(Space *s);
	void Draw(SDL_Renderer *s, SDL_Rect *dstrect);
	std::string GetName();
	std::shared_ptr<Space> GetSpaceAt(size_t x, size_t y);
	Map(std::string name, std::vector<std::vector<std::shared_ptr<Space>>> data);
	~Map();
};

#endif /* MAP_H */

