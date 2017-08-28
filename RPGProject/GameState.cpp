#include <iostream>
#include <memory>

#include "GameState.h"
#include "MapBuilder.h"

Map * GameState::GetMap()
{
	return _map;
}

GameState::GameState()
{
	auto builder = std::make_unique<MapBuilder>();
	if (!builder->ParseFile("maps/test.txt")) {
		std::cout << "Failed to parse map!" << std::endl;
	}
	_map = builder->GetMap();
}


GameState::~GameState()
{
	delete _map;
}
