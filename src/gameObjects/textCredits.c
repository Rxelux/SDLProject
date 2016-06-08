#include "gameObjectsFonct.h"

void InitTextCredits(S_scene_menu* sc,E_camera* camera){
	G_textCredits* textMenu = &sc->textCredits;

	textMenu->active = false;
	InitT(&textMenu->transform,0,0,1,1);
	InitT(&textMenu->sprite.srce,0,0,100,100);
	InitT(&textMenu->sprite.dest,0,0,1,1);
	textMenu->sprites[0] = LoadText(camera,"src/resources/Calibri.ttf","Created and directed by",87,0,13,20);
	textMenu->sprites[1] = LoadText(camera,"src/resources/Journey.ttf","Pelletier Robin",87,0,13,25);
	textMenu->sprites[2] = LoadText(camera,"src/resources/Calibri.ttf","Art Director",87,0,13,20);
	textMenu->sprites[3] = LoadText(camera,"src/resources/Journey.ttf","Pelletier Robin / special thanks to Michafrar",87,0,13,25);
	textMenu->sprites[4] = LoadText(camera,"src/resources/Calibri.ttf","Sound Designer and Composer",87,0,13,20);
	textMenu->sprites[5] = LoadText(camera,"src/resources/Journey.ttf","Austin Wintory and William Kage(nes remix)",87,0,13,25);
	textMenu->sprites[6] = LoadText(camera,"src/resources/Calibri.ttf","Lead Gameplay Designer",87,0,13,20);
	textMenu->sprites[7] = LoadText(camera,"src/resources/Journey.ttf","Gruson Emeric",87,0,13,25);
	textMenu->sprites[8] = LoadText(camera,"src/resources/Calibri.ttf","Sound Fx and scripting",87,0,13,20);
	textMenu->sprites[9] = LoadText(camera,"src/resources/Journey.ttf","Pelletier Robin",87,0,13,25);
	textMenu->sprite.frameTime = 0;

	int i;
	for(i = 0;i < 10;i++){
		InitV(&textMenu->pos[i],0,-120+(30)*i);
	}
}
void UpdateTextCredits(S_scene_menu* sc,E_input* input,E_camera* camera){
	G_textCredits* textCredits = &sc->textCredits;
	if(!textCredits->active)return;
	if(input->key[input->select]){
		input->key[input->select]=0;
		sc->textMenu.active = true;
		textCredits->active = false;
		sc->bm.active = true;
	}
}

void RenderTextCredits(S_scene_menu* sc,E_camera* camera){

	G_textCredits* textMenu = &sc->textCredits;
	if(!textMenu->active)return;
	int i;
	for(i = 0;i < 10;i++){
		EquV(&textMenu->transform.position,&textMenu->pos[i]);
			textMenu->sprite.texture = textMenu->sprites[i];
			SetRectText(&textMenu->sprite,&textMenu->transform,textMenu->sprite.texture);
			RenderGameObject(camera,&textMenu->sprite);
	}
}
