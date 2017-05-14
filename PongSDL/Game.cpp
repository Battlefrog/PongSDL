#include "Game.h"

void Game::GameLogic()
{

}

void Game::GameRendering( SDL_Renderer* renderer, Characters characters )
{
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
	SDL_RenderClear( renderer );

	SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

	// Draw Player
	SDL_RenderDrawRect( renderer, &characters.player );
	SDL_RenderFillRect( renderer, &characters.player );

	SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );

	// Draw Enemy
	SDL_RenderDrawRect( renderer, &characters.enemy );
	SDL_RenderFillRect( renderer, &characters.enemy );

	SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

	SDL_RenderDrawRect( renderer, &characters.point );
	SDL_RenderFillRect( renderer, &characters.point );

	SDL_RenderPresent( renderer );
}
