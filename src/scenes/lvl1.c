#include "../gameObjects/gameObjectsFonct.h"
#include "scenesFonct.h"

int InitScene_lvl1(S_scene_lvl1* sc,E_camera* camera){

	//init camera -> init window et renderer [renderer/renderer]

	InitT(&camera->transform,0,0,1,1);
	// Init le player
	InitPlayer(sc,camera);
	//InitBlocTest(sc);
	//init map
	InitTileMap(sc,camera);
	InitLvl1BG(sc,camera);

	InitScarf(sc,camera);

	return 0;
}

int UpdateScene_lvl1(S_scene_lvl1* sc,E_input* input,E_camera* camera){

	if(input->key[SDL_SCANCODE_P]){
		input->scene = 0;
	}

	//la on lance toute les fonction update de tout les gameobject du jeu
	SDL_RenderClear(camera->renderer);

	UpdateTileMap(sc,camera);
	UpdatePlayer(sc,input,camera);
	UpdateLvl1BG(sc,camera);
	UpdateScarf(sc,camera);


	RenderLvl1BG(sc,camera);
	RenderTileMap(sc,camera,0);
	RenderTileMap(sc,camera,1);


	RenderScarf(sc,camera);
	RenderTileMap(sc,camera,2);
	RenderPlayer(sc,camera);


	RenderTileMap(sc,camera,3);
	RenderTileMap(sc,camera,4);

	SDL_RenderPresent(camera->renderer);

	return 0;
}
