#pragma once
#include <SDL2\SDL.h>

#include "Engine.h"

class Characters
{
	public:

	SDL_Rect player { 50, 240, 15, 90 };
	SDL_Rect enemy { 750, 240, 15, 90 };
	SDL_Rect point { Engine::ScreenWidth / 2, Engine::ScreenHeight / 2, 10, 10 };

	const int PlayerSpeed = 10;

};