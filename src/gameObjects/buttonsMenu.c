#include "gameObjectsFonct.h"

void InitButtonsMenu(S_scene_menu* sc,E_camera* camera){
	G_buttonsMenu* bm = &sc->bm;

	bm->active = 1;

	int i;
	for(i = 0;i < 4;i++){
		InitT(&bm->buttons[i].transform,0,120+(30*i),1,1);
		InitT(&bm->buttons[i].sprite.srce,0,0,100,100);
		InitT(&bm->buttons[i].sprite.dest,0,0,1,1);
	}

	bm->buttons[0].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","Play",87,0,13,30);
	bm->buttons[1].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","Option",87,0,13,30);
	bm->buttons[2].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","Credits",87,0,13,30);
	bm->buttons[3].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","Quit",87,0,13,30);
	bm->buttons[0].hover = true;

	bm->ButtonSound = Mix_LoadWAV( "./src/resources/ButtonSound.wav" );
	bm->ButtonSoundValid = Mix_LoadWAV( "./src/resources/ButtonSoundValid.wav" );
}

void UpdateButtonsMenu(S_scene_menu* sc,E_input* input,E_camera* camera){
	G_buttonsMenu* bm = &sc->bm;
	if(!bm->active)return;
	int i;
	for(i = 0;i < 4;i++){
		if(bm->buttons[i].hover == true){
			LerpF(&bm->buttons[i].transform.position.x,20,0.1);
			switch(i){
				case 0 :
					bm->buttons[0].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","-Play",107,20,33,32);
					if(input->key[input->select]){
						Mix_PlayChannel( -1, bm->ButtonSoundValid, 0 );
						input->key[input->select]=0;
						input->scene = 1;
					}
				break;

				case 1 :
					bm->buttons[1].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","-Option",107,20,33,32);
					if(input->key[input->select]){
						Mix_PlayChannel( -1, bm->ButtonSoundValid, 0 );
						input->key[input->select]=0;
						sc->bo.active = true;
						sc->textMenu.active = false;
						bm->active = false;
					}
				break;

				case 2 :
					bm->buttons[2].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","-Credits",107,20,33,32);
					if(input->key[input->select]){
						Mix_PlayChannel( -1, bm->ButtonSoundValid, 0 );
						input->key[input->select]=0;
						sc->textMenu.active = false;
						sc->textCredits.active = true;
						bm->active = false;
					}
				break;

				case 3 :
					bm->buttons[3].sprite.texture =LoadText(camera,"./src/resources/journey.ttf","-Quit",107,20,33,32);
					if(input->key[input->select]){
						Mix_PlayChannel( -1, bm->ButtonSoundValid, 0 );
						input->key[input->select]=0;
						input->quit=1;
					}
				break;

			}
			if(input->key[input->up]){
				if(i==0){
					bm->buttons[3].hover = true;
				}else{
					bm->buttons[i-1].hover = true;
				}
				bm->buttons[i].hover = false;
			}
			if(input->key[input->down]){
				if(i==3){
					bm->buttons[0].hover = true;
				}else{
					bm->buttons[i+1].hover = true;
				}
				bm->buttons[i].hover = false;
			}
			if(input->key[input->up] || input->key[input->down]){
				input->key[input->up] = 0;
				input->key[input->down] = 0;
				Mix_PlayChannel( -1, bm->ButtonSound, 0 );
				switch(i){
					case 0 :
						bm->buttons[0].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","Play",87,0,13,30);
					break;

					case 1 :
						bm->buttons[1].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","Option",87,0,13,30);
					break;

					case 2 :
						bm->buttons[2].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","Credits",87,0,13,30);
					break;

					case 3 :
						bm->buttons[3].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","Quit",87,0,13,30);
					break;
				}
			}
		}else{
			LerpF(&bm->buttons[i].transform.position.x,0,0.1);
		}
	}
}

void RenderButtonsMenu(S_scene_menu* sc,E_camera* camera){

	G_buttonsMenu* bm = &sc->bm;
	if(!bm->active)return;
	int i;
	for(i = 0;i < 4;i++){
		SetRectText(&bm->buttons[i].sprite,&bm->buttons[i].transform,bm->buttons[i].sprite.texture);
		RenderGameObject(camera,&bm->buttons[i].sprite);
	}
}
