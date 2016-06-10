#include "engine/engineStruct.h"
#include "header.h"
#include "scenes/scenesFonct.h"
#include "SDLSetup/SDLSetup.h"

int main( int argc, char* args[] )
{
	//init toute les lib de SDL2 [renderer/initialize]

	if ( !InitAllSDL() )
		return 0;
	E_input input;							//le E_input qui gere les entrée clavier,souris et manette pour le jeu
	InitEvents(&input);
	E_camera camera;
	if(!InitCamera(&camera)){
		return 101;
	}

	S_scene_menu men;
	S_scene_lvl1 lv1;
	S_scene_map map;
	//S_scene_cutscene cts;

	while(!input.quit)
	{
		UpdateEvents(&input);
		switch(input.scene){
		case 0 :
			InitScene_menu(&men,&input,&camera);
			input.scene = 10;
			break;
		case 1 :
			InitScene_map(&map,&camera);
			input.scene = 11;
			break;
		case 2 :
			InitScene_lvl1(&lv1,&camera);
			input.scene = 12;
			break;
		case 3 :
			//InitScene_cutscene(&cts,&camera);
			input.scene = 13;
			break;


		case 10 :
			UpdateScene_menu(&men,&input,&camera);
			break;
		case 11 :
			UpdateScene_map(&map,&input,&camera);
			break;
		case 12 :
			UpdateScene_lvl1(&lv1,&input,&camera);
			break;
		case 13 :
			//UpdateScene_cutscene(&cts,&input,&camera);
			break;

		}
		// 16msec ~60 fps
		SDL_Delay( 16 );
	}
}
