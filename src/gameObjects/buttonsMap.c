#include "gameObjectsFonct.h"

void InitButtonsMap(S_scene_map* sc,E_camera* camera){
	G_buttonsMap* bm = &sc->bm;

	bm->active = 1;

	InitT(&bm->buttons[0].transform,-92*2,12*2,1,1);
	InitT(&bm->buttons[1].transform,12*2,100*2,1,1);
	InitT(&bm->buttons[2].transform,92*2,100*2,1,1);
	InitT(&bm->buttons[3].transform,72*2,-12*2,1,1);
	InitT(&bm->buttons[4].transform,36*2,-52*2,1,1);
	InitT(&bm->transform,0,0,1,1);

	InitT(&bm->sprite.srce,0,0,14,18);
	InitT(&bm->sprite.dest,0,0,14,18);
	bm->sprite.texture = LoadTexture(camera,"src/resources/mapPlayer.png");
	bm->buttons[0].hover = true;

	bm->ButtonSound = Mix_LoadWAV( "src/resources/ButtonSound.wav" );
	bm->ButtonSoundValid = Mix_LoadWAV( "src/resources/ButtonSoundValid.wav" );
}

void UpdateButtonsMap(S_scene_map* sc,E_input* input,E_camera* camera){
	G_buttonsMap* bm = &sc->bm;
	int i;
	for(i = 0;i < 5;i++){

		switch(i){
			case 0 :
				if(input->key[input->select]){
					Mix_PlayChannel( -1, bm->ButtonSoundValid, 0 );
					input->scene = 2;
					input->key[SDL_SCANCODE_RETURN]=0;
				}
			break;

		}
		if(input->key[input->select]){
			input->scene = 2;
		}

		if(bm->buttons[i].hover == true){
			LerpV(&bm->transform.position,&bm->buttons[i].transform.position,0.1);
			if(input->key[input->up]){
				if(i==0){
					bm->buttons[4].hover = true;
				}else{
					bm->buttons[i-1].hover = true;
				}
				bm->buttons[i].hover = false;
				input->key[SDL_SCANCODE_W] = 0;
				Mix_PlayChannel( -1, bm->ButtonSound, 0 );

			}
			if(input->key[input->down]){
				if(i==4){
					bm->buttons[0].hover = true;
				}else{
					bm->buttons[i+1].hover = true;
				}
				bm->buttons[i].hover = false;
				input->key[SDL_SCANCODE_S] = 0;
				Mix_PlayChannel( -1, bm->ButtonSound, 0 );
			}
		}
	}

}

void RenderButtonsMap(S_scene_map* sc,E_camera* camera){

	G_buttonsMap* bm = &sc->bm;
	int i;
	for(i = 0;i < 5;i++){
		if(bm->buttons[i].hover == true){
			SetRectSprite(&bm->sprite,&bm->transform);
			RenderGameObject(camera,&bm->sprite);
		}
	}
}
