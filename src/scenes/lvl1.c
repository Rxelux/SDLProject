#include "../gameObjects/gameObjectsFonct.h"
#include "scenesFonct.h"

int InitScene_lvl1(S_scene_lvl1* sc){

	//init camera -> init window et renderer [renderer/renderer]
	if(!InitCamera(sc)){
		return 101;
	}
	//init le tableau pour les inputs (voir events) [events/input]
	InitEvents(&sc->input);
	// Init le player
	InitPlayer(sc);
	//InitBlocTest(sc);
	//init map
	InitTileMap(sc);

	return 0;
}

int UpdateScene_lvl1(S_scene_lvl1* sc){

	//la on lance toute les fonction update de tout les gameobject du jeu
	UpdateEvents(&sc->input);

	UpdateTileMap(sc);
	SDL_RenderClear(sc->camera.renderer);

	RenderTileMap(sc,0);
	RenderTileMap(sc,1);
	RenderTileMap(sc,2);
	RenderPlayer(sc);
	RenderTileMap(sc,3);
	RenderTileMap(sc,4);
	RenderTileMap(sc,5);
	UpdatePlayer(sc);
	SDL_RenderPresent(sc->camera.renderer);

	return 0;
}
