#pragma once
#include <SDL2/SDL.h>
#include "Characters.h"

class Game
{
	public:

	void GameLogic();
	void GameRendering( SDL_Renderer* renderer, Characters characters );

};