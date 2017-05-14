#include "Engine.h"

void Engine::End( SDL_Renderer* renderer, SDL_Window* window )
{
	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();
}
