#include "gameObjectsFonct.h"

void InitTextMenu(S_scene_menu* sc,E_camera* camera){
	G_textMenu* textMenu = &sc->textMenu;

	textMenu->active = 1;
	InitT(&textMenu->transform,0,0,1,1);
	InitT(&textMenu->sprite.srce,0,0,100,100);
	InitT(&textMenu->sprite.dest,0,0,1,1);
	textMenu->sprites[0] = LoadText(camera,"src/resources/journey.ttf","J O U R N E Y",87,0,13,40);
	textMenu->sprites[1] = LoadText(camera,"src/resources/Calibri.ttf","c 19XX 2012",87,0,13,20);
	textMenu->sprites[2] = LoadText(camera,"src/resources/Calibri.ttf","ThatGameCompany",87,0,13,20);
	textMenu->sprites[3] = LoadText(camera,"src/resources/Calibri.ttf","SCE Santa Monica Studio",87,0,13,20);
	textMenu->sprite.frameTime = 0;
	InitV(&textMenu->pos[0],0,-20);
	InitV(&textMenu->pos[1],0,40);
	InitV(&textMenu->pos[2],0,60);
	InitV(&textMenu->pos[3],0,80);
}


void RenderTextMenu(S_scene_menu* sc,E_camera* camera){

	G_textMenu* textMenu = &sc->textMenu;
	if(!textMenu->active)return;

	int i;
	for(i = 0;i < 4;i++){
			EquV(&textMenu->transform.position,&textMenu->pos[i]);
				textMenu->sprite.texture = textMenu->sprites[i];
				SetRectText(&textMenu->sprite,&textMenu->transform,textMenu->sprite.texture);
				RenderGameObject(camera,&textMenu->sprite);
		}
}
