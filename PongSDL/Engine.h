#pragma once

#include <SDL2\SDL.h>

class Engine
{
	public:

	void Startup();
	void End( SDL_Renderer* renderer, SDL_Window* window );

	// Screen dimension constants
	static constexpr int ScreenWidth = 800;
	static constexpr int ScreenHeight = 600;
};