//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>

#include "Game.h"
#include "Engine.h"
#include "Characters.h"


#undef main

int main( int argc, char* args[] )
{
	// The window
	SDL_Window* window = nullptr;

	// The surface contained by the window
	SDL_Surface* screenSurface = nullptr;

	// Renderer
	SDL_Renderer* renderer = nullptr;

	Characters characters;

	Game Game;

	Engine Engine;

	// Initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	}
	else
	{

		// Create window
		window = SDL_CreateWindow( "PongSDL", 
								   SDL_WINDOWPOS_UNDEFINED, 
								   SDL_WINDOWPOS_UNDEFINED, 
								   Engine::ScreenWidth,
								   Engine::ScreenHeight,
								   SDL_WINDOW_SHOWN );

		renderer = SDL_CreateRenderer( window,
									   -1,
									   SDL_RENDERER_ACCELERATED );


		if ( window == nullptr )
		{
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		}

		if ( renderer == nullptr )
		{
			std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		}

		bool quit = false;

		SDL_Event e;

		while ( !quit )
		{
			while ( SDL_PollEvent( &e ) != 0 )
			{
				if ( e.type == SDL_QUIT )
				{
					quit = true;
				}
				else if ( e.type == SDL_KEYDOWN )
				{
					// TODO: Movement feels odd and not natural.
					//       Also the paddle isn't constrained
					switch ( e.key.keysym.sym )
					{
						case SDLK_UP:
							characters.player.y -= characters.PlayerSpeed;
							break;
						case SDLK_DOWN:
							characters.player.y += characters.PlayerSpeed;
							break;
					}
				}

				Game.GameRendering(renderer, characters);

			}
		}
	}

	Engine.End( renderer, window );

	return 0;
}