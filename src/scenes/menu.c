#include "../gameObjects/gameObjectsFonct.h"
#include "scenesFonct.h"

int InitScene_menu(S_scene_menu* sc,E_input* input,E_camera* camera){

	InitT(&camera->transform,0,0,1,1);
	InitMenuBG(sc,camera);
	InitTextMenu(sc,camera);
	InitTextCredits(sc,camera);
	InitButtonsMenu(sc,camera);
	InitButtonsOption(sc,input,camera);
	return 0;
}

int UpdateScene_menu(S_scene_menu* sc,E_input* input,E_camera* camera){

	SDL_RenderClear(camera->renderer);

	UpdateButtonsMenu(sc,input,camera);
	UpdateButtonsOption(sc,input,camera);
	UpdateTextCredits(sc,input,camera);

	RenderMenuBG(sc,camera);
	RenderTextMenu(sc,camera);
	RenderTextCredits(sc,camera);
	RenderButtonsMenu(sc,camera);
	RenderButtonsOption(sc,camera);

	SDL_RenderPresent(camera->renderer);
	return 0;
}
