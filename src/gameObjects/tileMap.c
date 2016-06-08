#include "gameObjectsFonct.h"

void InitTileMap(S_scene_lvl1* sc,E_camera* camera){

	G_tileMap* tileMap = &sc->tileMap;
	tileMap->active = 1;
	InitT(&tileMap->transform,0,0,10,10);
	InitT(&tileMap->sprite.srce,0,0,16,16);
	InitT(&tileMap->sprite.dest,0,0,16,16);
	tileMap->sprites[0] = tileMap->sprites[1] = tileMap->sprites[2] = tileMap->sprites[3] = tileMap->sprites[4] = LoadTexture(camera,"src/resources/tileJourneyA2.png");
	tileMap->sprite.frameTime = 0;
	tileMap->sizeMapX = 1500;
	tileMap->sizeMapY = 32;
	tileMap->sizeTileSetX = 28;
	tileMap->sizeTileSetY = 7;
	InitT(&tileMap->paralax[0],0,0,0.75,0.75);
	InitT(&tileMap->paralax[1],0,0,1,1);
	InitT(&tileMap->paralax[2],0,0,1,1);
	InitT(&tileMap->paralax[3],0,0,1,1);
	InitT(&tileMap->paralax[4],0,0,1.25,1.25);
	int i,j;
	FILE *myFile;
	myFile = fopen("src/resources/lvl1B.txt", "r");
	if (myFile == NULL){

		printf("Error Reading File\n");
		exit (0);
	}
	for (j = 0; j < 5; j++){
		for (i = 0; i < tileMap->sizeMapX * tileMap->sizeMapY; i++){
				fscanf(myFile, "%d,",&tileMap->tileRef[j][i]);

		}
		printf("%d \n",tileMap->tileRef[j][i]);
		printf("%d, %d ,\n",j,i);
	}

	fclose(myFile);
	for (i = 0; i < tileMap->sizeTileSetX * tileMap->sizeTileSetY; i++){
		switch(i){
		case 26:
		case 27:
		case 28:
		case 169:
		case 170:
		case 171:
		case 172:
		case 0: InitH(&tileMap->hitBox[i],4,4,4,-4,-4,-4,-4,4,0,0,0,0,0);break;
		case 29:
		case 4: InitH(&tileMap->hitBox[i],8,8,8,-8,-8,8,0,0,0,0,0,0,3);break;
		case 32:
		case 7: InitH(&tileMap->hitBox[i],8,8,-8,-8,-8,8,0,0,0,0,0,0,3);break;
		case 63:InitH(&tileMap->hitBox[i],-8,-8,8,8,8,8,0,0,0,0,0,0,3); break;
		default: InitH(&tileMap->hitBox[i],8,8,8,-8,-8,-8,-8,8,0,0,0,0,4);break;
		}
	}
}

void UpdateTileMap(S_scene_lvl1* sc,E_camera* camera){

	G_tileMap* tileMap = &sc->tileMap;
	P_vector dest = VMul(&camera->transform.position,(1 - 0.75));
	EquV(&tileMap->paralax[0].position,&dest);
	dest = VMul(&camera->transform.position,(1 - 1.25));
	EquV(&tileMap->paralax[4].position,&dest);

}


void RenderTileMap(S_scene_lvl1* sc,E_camera* camera,int j){

	G_tileMap* tileMap = &sc->tileMap;
	tileMap->sprite.texture = tileMap->sprites[j];
	int i;
	//P_vector saveScale = VEqu(&tileMap->transform.scale);

	//EquV(&tileMap->transform.scale,&tileMap->paralax[j].scale);
	//printf("%f\n",tileMap->transform.scale.x);
	for(i = 0;i < tileMap->sizeMapX * tileMap->sizeMapY;i++){

		if(tileMap->tileRef[j][i]!=0){
			tileMap->transform.position.x = i%tileMap->sizeMapX * tileMap->sprite.dest.scale.x * tileMap->transform.scale.x * tileMap->paralax[j].scale.x
					- (tileMap->sizeMapX*tileMap->sprite.dest.scale.x * tileMap->transform.scale.x * tileMap->paralax[j].scale.x)/2.0 + tileMap->paralax[j].position.x;
			tileMap->transform.position.y = i/tileMap->sizeMapX * tileMap->sprite.dest.scale.y * tileMap->transform.scale.y * tileMap->paralax[j].scale.y
					- (tileMap->sizeMapY*tileMap->sprite.dest.scale.y * tileMap->transform.scale.y * tileMap->paralax[j].scale.y)/2.0 + tileMap->paralax[j].position.y;

			tileMap->sprite.srce.position.x = ((tileMap->tileRef[j][i]-1)%tileMap->sizeTileSetX);
			tileMap->sprite.srce.position.y = ((tileMap->tileRef[j][i]-1)/tileMap->sizeTileSetX);

			//---SETSRCERECT---------------
			tileMap->sprite.srcerect.x = tileMap->sprite.srce.position.x * tileMap->sprite.srce.scale.x;
			tileMap->sprite.srcerect.y = tileMap->sprite.srce.position.y * tileMap->sprite.srce.scale.y;
			tileMap->sprite.srcerect.w = tileMap->sprite.srce.scale.x;
			tileMap->sprite.srcerect.h = tileMap->sprite.srce.scale.y;

			tileMap->sprite.dest.position.x = tileMap->transform.position.x - (tileMap->sprite.dest.scale.x/2) * tileMap->transform.scale.x;
			tileMap->sprite.dest.position.y = tileMap->transform.position.y - (tileMap->sprite.dest.scale.y/2) * tileMap->transform.scale.y;
			tileMap->sprite.destrect.w = tileMap->sprite.dest.scale.x * tileMap->transform.scale.x * tileMap->paralax[j].scale.x;
			tileMap->sprite.destrect.h = tileMap->sprite.dest.scale.y * tileMap->transform.scale.y * tileMap->paralax[j].scale.y;
			//-------

			if(DistanceV(&sc->player.transform.position,&tileMap->transform.position) < 500 && j == 3){
				SDL_SetTextureAlphaMod(tileMap->sprite.texture,DistanceV(&sc->player.transform.position,&tileMap->transform.position)*0.3 + 105);
			}else{
				SDL_SetTextureAlphaMod(tileMap->sprite.texture,255);
			}

			RenderGameObject(camera,&tileMap->sprite);

		}
		/*
		if(j == 2){
			int px = GetMapPos(&sc->player.transform.position,tileMap).x;
			int py = GetMapPos(&sc->player.transform.position,tileMap).y;

			printf("%d : %d \n",px,py);
			if(i%tileMap->sizeMapX >= px-2 && i%tileMap->sizeMapX <= px+2){
				if(i/tileMap->sizeMapX >= py-2 && i/tileMap->sizeMapX <= py+2){
					P_hitBox hb = HMatchPS(&tileMap->hitBox[tileMap->tileRef[j][i]],&tileMap->transform.position,&tileMap->transform.scale);
					DEBUGHITBOX (&hb,&sc->camera,0,0,128);
				}
			}
		}*/
	}
}

P_vector GetMapPos(P_vector* v,G_tileMap* tileMap){
	return VInit(round(v->x / (tileMap->sprite.dest.scale.x * tileMap->transform.scale.x) + tileMap->sizeMapX/2),
			round(v->y / (tileMap->sprite.dest.scale.y * tileMap->transform.scale.x)+ tileMap->sizeMapY/2));
}

