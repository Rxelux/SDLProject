#include "gameObjectsFonct.h"

void InitTextScores(S_scene_menu* sc,E_input* input,E_camera* camera){
	G_textScores* textMenu = &sc->textScores;

	textMenu->active = false;
	InitT(&textMenu->transform,0,0,1,1);
	InitT(&textMenu->sprite.srce,0,0,100,100);
	InitT(&textMenu->sprite.dest,0,0,1,1);
	textMenu->sprite.frameTime = 0;

	int i;
	for(i = 0;i < 10;i++){
		printf("%s\n",input->scores[i]);
		textMenu->sprites[i] = LoadText(camera,"./src/resources/Calibri.ttf",input->scores[i],87,0,13,20);
		InitV(&textMenu->pos[i],0,120-(30)*i);
	}
}
void UpdateTextScores(S_scene_menu* sc,E_input* input,E_camera* camera){
	G_textScores* textScores = &sc->textScores;
	if(!textScores->active)return;
	if(input->key[input->select]){
		input->key[input->select]=0;
		sc->bo.active = true;
		textScores->active = false;
	}
}

void RenderTextScores(S_scene_menu* sc,E_camera* camera){

	G_textScores* textScores = &sc->textScores;
	if(!textScores->active)return;
	int i;
	for(i = 0;i < 10;i++){
		EquV(&textScores->transform.position,&textScores->pos[i]);
		textScores->sprite.texture = textScores->sprites[i];
			SetRectText(&textScores->sprite,&textScores->transform,textScores->sprite.texture);
			RenderGameObject(camera,&textScores->sprite);
	}
}
