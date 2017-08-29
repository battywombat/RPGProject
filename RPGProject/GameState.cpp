#include <iostream>
#include <memory>

#include "GameState.h"
#include "MapBuilder.h"

Map *GameState::GetMap()
{
	return _map;
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
	_map = builder->GetMap();
	_p = new Player();
	_map->PlayerEnterMap(_p, 1, 1);
}


GameState::~GameState()
{
}
