#include <iostream>

#include "GameState.h"
#include "MapBuilder.h"

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
}


GameState::~GameState()
{
}
