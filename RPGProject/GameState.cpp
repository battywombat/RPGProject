#include <iostream>

#include "GameState.h"
#include "MapBuilder.h"
#include "Graphics.h"

void GameState::_DrawCursor(SDL_Renderer *ren)
{
	int x = _p->GetX(), y = _p->GetY();
	if (_CursorDirection == Direction::EAST || _CursorDirection == Direction::NORTHEAST || _CursorDirection == Direction::SOUTHEAST) {
		x += 1;
	}
	if (_CursorDirection == Direction::WEST || _CursorDirection == Direction::NORTHWEST || _CursorDirection == Direction::SOUTHWEST) {
		x -= 1;
	}
	if (_CursorDirection == Direction::NORTH || _CursorDirection == Direction::NORTHEAST || _CursorDirection == Direction::NORTHWEST) {
		y -= 1;
	}
	if (_CursorDirection == Direction::SOUTH || _CursorDirection == Direction::SOUTHEAST || _CursorDirection == Direction::SOUTHWEST) {
		y += 1;
	}
	SDL_Rect r;
	Graphics::GetSprite(0, &r);
	r.x = (x+2)*r.w;
	r.y = (y+1)*r.h;
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
	SDL_RenderDrawRect(ren, &r);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
}

Space * GameState::GetSquarePointedByCursor()
{
	size_t x = _p->GetX(), y = _p->GetY();
	if (_CursorDirection == Direction::EAST || _CursorDirection == Direction::NORTHEAST || _CursorDirection == Direction::SOUTHEAST) {
		x += 1;
	}
	if (_CursorDirection == Direction::WEST || _CursorDirection == Direction::NORTHWEST || _CursorDirection == Direction::SOUTHWEST) {
		x -= 1;
	}
	if (_CursorDirection == Direction::NORTH || _CursorDirection == Direction::NORTHEAST || _CursorDirection == Direction::NORTHWEST) {
		y -= 1;
	}
	if (_CursorDirection == Direction::SOUTH || _CursorDirection == Direction::SOUTHEAST || _CursorDirection == Direction::SOUTHWEST) {
		y += 1;
	}
	Map *m = dynamic_cast<Map *>(_p->GetParent()->GetParent());
	if (x < 0 || x >= m->GetWidth() || y < 0 || y >= m->GetHeight()) {
		return nullptr;
	}
	return m->GetSpaceAt(x, y);
}

World *GameState::GetWorld()
{
	return _world;
}

Player *GameState::GetPlayer()
{
	return _p;
}

GameState::GameState()
{
	auto builder = std::make_unique<MapBuilder>();
	if (!builder->ParseFile("maps/test.txt")) {
		std::cout << "Failed to parse map!" << std::endl;
	}
	auto map1 = builder->GetMap();
	if (!builder->ParseFile("maps/test2.txt")) {
		std::cout << "Failed to parse map!" << std::endl;
	}
	auto map2 = builder->GetMap();
	auto v = std::vector<Map *>();
	_p = new Player();
	v.push_back(map1);
	v.push_back(map2);
	_world = new World(v);
	_world->AddPlayer(_p, 1, 1, 0);
	_CursorDirection = Direction::WEST;
}

void GameState::Draw(SDL_Renderer * ren, SDL_Rect *win_dim)
{
	SDL_Rect map_dim;
	map_dim.x = map_dim.y = 0;
	map_dim.w = win_dim->w / 2;
	map_dim.h = win_dim->h;
	_world->Draw(ren, &map_dim);
	_DrawCursor(ren);
}

void GameState::SetCursorDirection(Direction d)
{
	_CursorDirection = d;
}


GameState::~GameState()
{
	delete _world;
}
