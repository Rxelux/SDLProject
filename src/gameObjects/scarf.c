#include "gameObjectsFonct.h"

void InitScarf(S_scene_lvl1* sc,E_camera* camera){

	G_scarf* scarf = &sc->scarf;

	scarf->active = 1;
	InitT(&scarf->transform,0,0,10,10);
	InitT(&scarf->sprite.srce,0,0,64,16);
	InitT(&scarf->sprite.dest,0,0,64,16);
	InitT(&scarf->sprite2.srce,0,0,64,16);
	InitT(&scarf->sprite2.dest,0,0,64,16);
	scarf->sprite.texture = LoadTexture(camera,"./src/resources/Scarf.png");
	scarf->sprite2.texture = LoadTexture(camera,"./src/resources/Scarf.png");
	scarf->sprite.frameTime = 0;

}
void UpdateScarf(S_scene_lvl1* sc,E_camera* camera){
	G_scarf* scarf = &sc->scarf;


	int currentTime = SDL_GetTicks();
	if(currentTime - scarf->sprite.frameTime > PLAYER_FRAME){

		scarf->sprite.srce.position.y++;
		scarf->sprite2.srce.position.y++;
		if(scarf->sprite.srce.position.y > 11){
			scarf->sprite.srce.position.y = 0;

		}
		if(scarf->sprite2.srce.position.y > 23){
			scarf->sprite2.srce.position.y = 12;

		}

		scarf->sprite.frameTime = currentTime;
	}

	float f = 8.0 + 4*sc->player.power;
	scarf->sprite.srce.position.x = 64.0/(f)-1;
	scarf->sprite.srce.scale.x = f;
	scarf->sprite.dest.scale.x = f;

	float f2 = (float)sc->player.jumpTime/(float)sc->player.maxJumpTime;

	scarf->sprite2.srce.position.x = 64.0/(f*f2)-1;
	scarf->sprite2.srce.scale.x = f*f2;
	scarf->sprite2.dest.scale.x = f*f2;

	P_vector decal = VInit(-(10*f)/2 -20,-20);
	EquV(&scarf->transform.position,&sc->player.transform.position);
	AddV(&scarf->transform.position,&decal);

	SetRectSprite(&scarf->sprite,&scarf->transform);

	decal = VInit(-(10*f)*f2/2 -20,-20);
	EquV(&scarf->transform.position,&sc->player.transform.position);
	AddV(&scarf->transform.position,&decal);

	SetRectSprite(&scarf->sprite2,&scarf->transform);
}

void RenderScarf(S_scene_lvl1* sc,E_camera* camera){

	G_scarf* scarf = &sc->scarf;

	RenderGameObject(camera,&scarf->sprite);
	RenderGameObject(camera,&scarf->sprite2);

}
