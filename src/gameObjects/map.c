#include "gameObjectsFonct.h"

void InitMapBG(S_scene_map* sc,E_camera* camera){
	G_mapBG* mapBG = &sc->mapBG;

	mapBG->active = 1;
	InitT(&mapBG->transform,0,0,1,1);
	InitT(&mapBG->sprite.srce,0,0,256,256);
	InitT(&mapBG->sprite.dest,0,0,512,512);
	mapBG->sprite.texture = LoadTexture(camera,"./src/resources/worldMap.png");
	mapBG->sprite.frameTime = 0;
	SetRectSprite(&mapBG->sprite,&mapBG->transform);
}

void RenderMapBG(S_scene_map* sc,E_camera* camera){

	G_mapBG* mapBG = &sc->mapBG;
	RenderGameObject(camera,&mapBG->sprite);

}
