
#include "header.h"
#include "renderer/renderer.h"
#include "gameObject/gameObject.h"

void DrawGame(SDL_Renderer** renderer,SDL_Rect* rect);

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
	InitPlayer(&player);

	SDL_Rect playerRect;


	// init tileMap
	//T_map map;
	//initMap(&map);

	while(!input.key[SDLK_ESCAPE] && !input.quit)
	{
		//la on lance toute les fonction update de tout les gameobject du jeu
		UpdateEvents(&input);
		UpdatePlayer(&player,&input);
		playerRect.x = player.transform.position.x;
		playerRect.y = player.transform.position.y;
		playerRect.w = player.transform.scale.x;
		playerRect.h = player.transform.scale.y;

		//ENDTODO

		DrawGame(&renderer,&playerRect);

		// Add a 16msec delay to make our game run at ~60 fps
		SDL_Delay( 16 );
	}
}

void DrawGame(SDL_Renderer** renderer,SDL_Rect* rect)
{
	// Change color orange
	SDL_SetRenderDrawColor( *renderer, 255, 200, 0, 255 );

	// Clear the window and make it all orange
	SDL_RenderClear( *renderer );

	// Change color to blue
	SDL_SetRenderDrawColor( *renderer, 0, 0, 255, 255 );

	// Render our "player"
	SDL_RenderFillRect( *renderer, rect );

	// Render the changes above
	SDL_RenderPresent( *renderer);

}
