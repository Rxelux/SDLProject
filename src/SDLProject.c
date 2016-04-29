#include "header.h"
#include "scenes/scenesFonct.h"
#include "SDLSetup/SDLSetup.h"

int main( int argc, char* args[] )
{
	//init toute les lib de SDL2 [renderer/initialize]

	if ( !InitAllSDL() )
		return 0;

	S_scene_lvl1 sc;

	InitScene_lvl1(&sc);

	while(!sc.input.key[SDLK_ESCAPE] && !sc.input.quit)
	{
		UpdateScene_lvl1(&sc);
		// 16msec ~60 fps
		SDL_Delay( 16 );
	}
}
