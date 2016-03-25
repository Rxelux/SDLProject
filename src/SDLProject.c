
#include "header.h"
#include "gameEngine/gameEngine.h"
#include "gameObjects/gameObjects.h"

void DrawGame(SDL_Renderer** renderer);

int main( int argc, char* args[] )
{
	//init toute les lib de SDL2 [renderer/initialize]
	if ( !InitAllSDL() )
		return 0;

	G_gameEngine ge;

	//crée la fenetre du jeu [renderer/initialize]
	if ( !CreateWindow(&ge.window,0,0,SCREEN_WIDTH,SCREEN_HEIGHT) )
		return 0;

	//crée le renderer associé a la fenetre [renderer/initialize]
	if ( !CreateRenderer(&ge.window,&ge.renderer) )
		return 0;
	//met le renderer a la taille de la fenetre
	SetupRenderer(&ge.renderer,SCREEN_WIDTH,SCREEN_HEIGHT);

	//init le tableau pour les inputs (voir events) [events/input]
	InitEvents(&ge.input);

	// Init le player
	InitPlayer(&ge);

	// init tileMap
	//T_map map;
	//initMap(&map);

	while(!ge.input.key[SDLK_ESCAPE] && !ge.input.quit)
	{
		//la on lance toute les fonction update de tout les gameobject du jeu
		UpdateEvents(&ge.input);
		UpdatePlayer(&ge);

		//ENDTODO

		DrawGame(&ge.renderer);
		RenderGameObjects(&ge.renderer,ge.gameObjects);
		// Render the changes above
		SDL_RenderPresent(ge.renderer);

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
