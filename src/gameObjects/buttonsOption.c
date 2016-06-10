#include "gameObjectsFonct.h"

void InitButtonsOption(S_scene_menu* sc,E_input* input,E_camera* camera){
	G_buttonsOption* bo = &sc->bo;
	bo->active = false;

	int i;
	for(i = 0;i < 10;i++){
		InitT(&bo->buttons[i].transform,0,-120+(30*i),1,1);
		InitT(&bo->buttons[i].sprite.srce,0,0,100,100);
		InitT(&bo->buttons[i].sprite.dest,0,0,1,1);
	}
	bo->into=-1;
	char tchar[20];
	char ichar[10];

	strcpy(tchar,"Music:");
	sprintf(ichar, "%d", input->musicVol);
	strcat(tchar,ichar);
	Mix_VolumeMusic(input->musicVol);
	bo->buttons[0].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
	strcpy(tchar,"Sound:");
	sprintf(ichar, "%d", input->soundVol);
	strcat(tchar,ichar);
	Mix_Volume(-1,input->soundVol);
	bo->buttons[1].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
	strcpy(tchar,"Up:");
	strcat(tchar,SDL_GetScancodeName(input->up));
	bo->buttons[2].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
	strcpy(tchar,"Down:");
	strcat(tchar,SDL_GetScancodeName(input->down));
	bo->buttons[3].sprite.texture =LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
	strcpy(tchar,"Left:");
	strcat(tchar,SDL_GetScancodeName(input->left));
	bo->buttons[4].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
	strcpy(tchar,"Right:");
	strcat(tchar,SDL_GetScancodeName(input->right));
	bo->buttons[5].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
	strcpy(tchar,"Select:");
	strcat(tchar,SDL_GetScancodeName(input->select));
	bo->buttons[6].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
	bo->buttons[7].sprite.texture =LoadText(camera,"./src/resources/journey.ttf","ResetScores",87,0,13,30);
	bo->buttons[8].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","ShowScores",87,0,13,30);
	bo->buttons[9].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","Back",87,0,13,30);
	bo->buttons[0].hover = true;

	bo->ButtonSound = Mix_LoadWAV( "./src/resources/ButtonSound.wav" );
	bo->ButtonSoundValid = Mix_LoadWAV( "./src/resources/ButtonSoundValid.wav" );
}

void UpdateButtonsOption(S_scene_menu* sc,E_input* input,E_camera* camera){
	G_buttonsOption* bo = &sc->bo;
	if(!bo->active)return;
	int i;
	char tchar[20];
	char ichar[10];
	for(i = 0;i < 10;i++){
		if(bo->buttons[i].hover == true){
			LerpF(&bo->buttons[i].transform.position.x,20,0.1);
			switch(i){
				case 0 :
					if(input->key[input->right] && bo->into==-1){
						input->musicVol++;
					}
					if(input->key[input->left] && bo->into==-1){
						input->musicVol--;
					}
					if(input->musicVol>100)input->musicVol=100;
					if(input->musicVol<0)input->musicVol=0;
					Mix_VolumeMusic(input->musicVol);
					strcpy(tchar,"<Music:");
					sprintf(ichar, "%d>", input->musicVol);
					strcat(tchar,ichar);
					bo->buttons[0].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,107,20,33,32);
				break;
				case 1 :
					if(input->key[input->right] && bo->into==-1){
						input->soundVol++;
					}
					if(input->key[input->left] && bo->into==-1){
						input->soundVol--;
					}
					if(input->soundVol>100)input->soundVol=100;
					if(input->soundVol<0)input->soundVol=0;
					Mix_Volume(-1,input->soundVol);
					strcpy(tchar,"<Sound:");
					sprintf(ichar, "%d>", input->soundVol);
					strcat(tchar,ichar);
					bo->buttons[1].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,107,20,33,32);
				break;
				case 2 :
					strcpy(tchar,"-Up:");
					strcat(tchar,SDL_GetScancodeName(input->up));
					bo->buttons[2].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,107,20,33,32);
					if(input->key[input->select] && bo->into==-1){
						bo->into=2;
						Mix_PlayChannel( -1, bo->ButtonSoundValid, 0 );
						input->lastKeyPress = -1;
					}
					if(bo->into==2){
						bo->buttons[2].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","-PressKey",107,20,33,32);
						if(input->lastKeyPress != -1 && testKey(input,input->lastKeyPress)){
							input->up = input->lastKeyPress;
							bo->into=-1;
							memset(&input->key,0,sizeof(input->key));
						}
					}
				break;
				case 3 :
					strcpy(tchar,"-Down:");
					strcat(tchar,SDL_GetScancodeName(input->down));
					bo->buttons[3].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,107,20,33,32);
					if(input->key[input->select] && bo->into==-1){
						bo->into=3;
						Mix_PlayChannel( -1, bo->ButtonSoundValid, 0 );
						input->lastKeyPress = -1;
					}
					if(bo->into==3){
						bo->buttons[3].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","-PressKey",107,20,33,32);

						if(input->lastKeyPress != -1 && testKey(input,input->lastKeyPress)){
							input->down = input->lastKeyPress;
							bo->into=-1;
							memset(&input->key,0,sizeof(input->key));
						}
					}
				break;
				case 4 :
					strcpy(tchar,"-Left:");
					strcat(tchar,SDL_GetScancodeName(input->left));
					bo->buttons[4].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,107,20,33,32);
					if(input->key[input->select] && bo->into==-1){
						bo->into=4;
						Mix_PlayChannel( -1, bo->ButtonSoundValid, 0 );
						input->lastKeyPress = -1;
					}
					if(bo->into==4){
						bo->buttons[4].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","-PressKey",107,20,33,32);
						if(input->lastKeyPress != -1 && testKey(input,input->lastKeyPress)){
							input->left = input->lastKeyPress;
							bo->into=-1;
							memset(&input->key,0,sizeof(input->key));
						}
					}
				break;
				case 5 :
					strcpy(tchar,"-Right:");
					strcat(tchar,SDL_GetScancodeName(input->right));
					bo->buttons[5].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,107,20,33,32);
					if(input->key[input->select] && bo->into==-1){
						bo->into=5;
						Mix_PlayChannel( -1, bo->ButtonSoundValid, 0 );
						input->lastKeyPress = -1;
					}
					if(bo->into==5){
						bo->buttons[5].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","-PressKey",107,20,33,32);
						if(input->lastKeyPress != -1 && testKey(input,input->lastKeyPress)){
							input->right = input->lastKeyPress;
							bo->into=-1;
							memset(&input->key,0,sizeof(input->key));
						}
					}
				break;
				case 6 :
					strcpy(tchar,"-Select:");
					strcat(tchar,SDL_GetScancodeName(input->select));
					bo->buttons[6].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,107,20,33,32);
					if(input->key[input->select] && bo->into==-1){
						bo->into=6;
						Mix_PlayChannel( -1, bo->ButtonSoundValid, 0 );
						input->lastKeyPress = -1;
					}
					if(bo->into==6){
						bo->buttons[6].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","-PressKey",107,20,33,32);
						if(input->lastKeyPress != -1 && testKey(input,input->lastKeyPress)){
							input->select = input->lastKeyPress;
							bo->into=-1;
							memset(&input->key,0,sizeof(input->key));
						}
					}
				break;
				case 7 :
					bo->buttons[7].sprite.texture =LoadText(camera,"./src/resources/journey.ttf","/!\\ResetScores",107,20,33,32);
					if(input->key[input->select]){
						Mix_PlayChannel( -1, bo->ButtonSoundValid, 0 );
						input->key[input->select]=0;
						FILE *myFile;
						myFile = fopen("./src/resources/scores.txt", "r+");
						if (myFile == NULL){

							printf("Error Reading File\n");
							exit (0);
						}
						fprintf(myFile,"00:47:00:000,00:38:00:000,00:30:00:000,00:23:00:000,00:17:00:000,00:12:00:000,00:08:00:000,00:05:00:000,00:03:00:000,00:02:00:000,");

						fclose(myFile);
					}
				break;
				case 8 :
					bo->buttons[8].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","-ShowScores",107,20,33,32);
					if(input->key[input->select]){
						Mix_PlayChannel( -1, bo->ButtonSoundValid, 0 );
						input->key[input->select]=0;
						FILE *myFile2;
						myFile2 = fopen("./src/resources/scores.txt", "r+");
						if (myFile2 == NULL){

							printf("Error Reading File\n");
							exit (0);
						}

						int i;
						for(i = 0;i < 10;i++){
							fscanf(myFile2, "%[^,],",input->scores[i]);
						}
						fclose(myFile2);
						InitTextScores(sc,input,camera);
						sc->bo.active = false;
						sc->textScores.active = true;
						bo->active = false;
					}
				break;
				case 9 :
					bo->buttons[9].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","-Back",107,20,33,32);

					FILE *myFile3;
					myFile3 = fopen("./src/resources/save.txt", "r+");
					if (myFile3 == NULL){

						printf("Error Reading File\n");
						exit (0);
					}

					fprintf(myFile3, "%d,%d,%d,%d,%d,%d,%d,",input->up,input->down,input->left,input->right,input->select,input->musicVol,input->soundVol);

					fclose(myFile3);

					if(input->key[input->select]){
						Mix_PlayChannel( -1, bo->ButtonSoundValid, 0 );
						input->key[input->select]=0;
						sc->bm.active = true;
						sc->textMenu.active = true;
						bo->active = false;
					}
				break;
			}
			if(input->key[input->up] && bo->into == -1){
				if(i==0){
					bo->buttons[9].hover = true;
				}else{
					bo->buttons[i-1].hover = true;
				}
				bo->buttons[i].hover = false;
			}
			if(input->key[input->down] && bo->into == -1){
				if(i==9){
					bo->buttons[0].hover = true;
				}else{
					bo->buttons[i+1].hover = true;
				}
				bo->buttons[i].hover = false;
			}
			if((input->key[input->up] || input->key[input->down]) && bo->into == -1){
				input->key[input->up] = 0;
				input->key[input->down] = 0;
				Mix_PlayChannel( -1, bo->ButtonSound, 0 );
				switch(i){
				case 0 :

					strcpy(tchar,"Music:");
					sprintf(ichar, "%d", input->musicVol);
					strcat(tchar,ichar);
					bo->buttons[0].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
				break;
				case 1 :
					strcpy(tchar,"Sound:");
					sprintf(ichar, "%d", input->soundVol);
					strcat(tchar,ichar);
					bo->buttons[1].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
				break;
				case 2 :
					strcpy(tchar,"Up:");
					strcat(tchar,SDL_GetScancodeName(input->up));
					bo->buttons[2].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
				break;
				case 3 :
					strcpy(tchar,"Down:");
					strcat(tchar,SDL_GetScancodeName(input->down));
					bo->buttons[3].sprite.texture =LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
				break;
				case 4 :
					strcpy(tchar,"Left:");
					strcat(tchar,SDL_GetScancodeName(input->left));
					bo->buttons[4].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
				break;
				case 5 :
					strcpy(tchar,"Right:");
					strcat(tchar,SDL_GetScancodeName(input->right));
					bo->buttons[5].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
				break;
				case 6 :
					strcpy(tchar,"Select:");
					strcat(tchar,SDL_GetScancodeName(input->select));
					bo->buttons[6].sprite.texture = LoadText(camera,"./src/resources/journey.ttf",tchar,87,0,13,30);
				break;
				case 7 :
					bo->buttons[7].sprite.texture =LoadText(camera,"./src/resources/journey.ttf","ResetScores",87,0,13,30);
				break;
				case 8 :
					bo->buttons[8].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","ShowScores",87,0,13,30);
				break;
				case 9 :
					bo->buttons[9].sprite.texture = LoadText(camera,"./src/resources/journey.ttf","Back",87,0,13,30);
				break;

				}
			}
		}else{
			LerpF(&bo->buttons[i].transform.position.x,0,0.1);
		}
	}

}

void RenderButtonsOption(S_scene_menu* sc,E_camera* camera){

	G_buttonsOption* bo = &sc->bo;
	if(!bo->active)return;
	int i;
	for(i = 0;i < 10;i++){
		SetRectText(&bo->buttons[i].sprite,&bo->buttons[i].transform,bo->buttons[i].sprite.texture);
		RenderGameObject(camera,&bo->buttons[i].sprite);
	}
}

bool testKey(E_input* input,int key){
	if(key == input->up || key == input->down || key == input->left || key == input->right || key == input->select){
		return 0;
	}
	return 1;
}
