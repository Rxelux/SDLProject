
#include "header.h"
#include "gameObject/player.h"

void DrawGame(SDL_Renderer** renderer);

int main( int argc, char* args[] )
{
	//init toute les lib de SDL2
	if ( !InitAllSDL() )
		return 0;

	SDL_Window* window;
	//changer ca avec des define


	if ( !CreateWindow(&window,0,0,SCREEN_WIDTH,SCREEN_HEIGHT) )
		return 0;
	SDL_Renderer* renderer;
	if ( !CreateRenderer(&window,&renderer) )
		return 0;

	SetupRenderer(&renderer,SCREEN_WIDTH,SCREEN_HEIGHT);

	//
	E_input input;
	InitEvents(&input);

	// Initialize le player
	G_gameObject player;
	InitPlayer(&player,&renderer);

	// init tileMap
	//T_map map;
	//initMap(&map);

	while(!input.key[SDLK_ESCAPE] && !input.quit)
	{
		//la on lance toute les fonction update de tout les gameobject du jeu
		UpdateEvents(&input);
		UpdatePlayer(&player,&input);

		//ENDTODO

		DrawGame(&renderer);
		RenderGameObject(&renderer,&player);
		// Render the changes above
		SDL_RenderPresent(renderer);

		// Add a 16msec delay to make our game run at ~60 fps
		SDL_Delay( 16 );
	}
}

void DrawGame(SDL_Renderer** renderer)
{
	// Change color orange
	SDL_SetRenderDrawColor( *renderer, 255, 200, 0, 255 );

	// Clear the window and make it all orange
	SDL_RenderClear( *renderer );
}
