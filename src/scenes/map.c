#include "../gameObjects/gameObjectsFonct.h"
#include "scenesFonct.h"

int InitScene_map(S_scene_map* sc,E_camera* camera){

	InitMapBG(sc,camera);
	InitButtonsMap(sc,camera);
	return 0;
}

int UpdateScene_map(S_scene_map* sc,E_input* input,E_camera* camera){

	SDL_RenderClear(camera->renderer);

	UpdateButtonsMap(sc,input,camera);

	RenderMapBG(sc,camera);
	RenderButtonsMap(sc,camera);

	SDL_RenderPresent(camera->renderer);
	return 0;
}
