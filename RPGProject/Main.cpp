#include <iostream>
#include <memory>

#include "GameState.h"
#include "SDLRenderer.h"

#undef main

int main()
{
	auto r = std::make_unique<SDLRenderer>(new GameState());
	r->Init();
	r->Start();

	return 0;
}