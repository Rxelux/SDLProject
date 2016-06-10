#include "gameObjectsFonct.h"

void InitMenuBG(S_scene_menu* sc,E_camera* camera){
	G_menuBG* menuBG = &sc->menuBG;

	menuBG->active = 1;
	InitT(&menuBG->transform,0,0,1,1);
	InitT(&menuBG->sprite.srce,0,0,512,512);
	InitT(&menuBG->sprite.dest,0,0,512,512);
	menuBG->sprite.texture = LoadTexture(camera,"./src/resources/BG.png");
	SetRectSprite(&menuBG->sprite,&menuBG->transform);

	menuBG->BGMusic = Mix_LoadMUS( "./src/resources/JourneyTitle.mp3" );
	if( Mix_PlayingMusic() == 0 )
	{
		//Play the music
		Mix_PlayMusic( menuBG->BGMusic, -1 );
	}
}

void InitLvl1BG(S_scene_lvl1* sc,E_camera* camera){
	G_menuBG* menuBG = &sc->menuBG;

	menuBG->active = 1;
	InitT(&menuBG->transform,0,0,4,4);
	InitT(&menuBG->sprite.srce,0,0,512,512);
	InitT(&menuBG->sprite.dest,0,0,512,512);
	menuBG->sprite.texture = LoadTexture(camera,"./src/resources/BG.png");
	SetRectSprite(&menuBG->sprite,&menuBG->transform);

}

void UpdateLvl1BG(S_scene_lvl1* sc,E_camera* camera){
	G_menuBG* menuBG = &sc->menuBG;
	EquV(&menuBG->transform.position,&camera->transform.position);
	SetRectSprite(&menuBG->sprite,&menuBG->transform);
}

void RenderMenuBG(S_scene_menu* sc,E_camera* camera){

	G_menuBG* menuBG = &sc->menuBG;

	RenderGameObject(camera,&menuBG->sprite);
}

void RenderLvl1BG(S_scene_lvl1* sc,E_camera* camera){

	G_menuBG* menuBG = &sc->menuBG;

	RenderGameObject(camera,&menuBG->sprite);
}
