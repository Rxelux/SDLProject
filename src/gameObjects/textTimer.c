#include "gameObjectsFonct.h"

void InitTextTimer(S_scene_lvl1* sc,E_camera* camera){
	G_textTimer* textTimer = &sc->textTimer;

	textTimer->active = 1;
	InitT(&textTimer->transform,0,0,1,1);
	InitT(&textTimer->sprite.srce,0,0,100,100);
	InitT(&textTimer->sprite.dest,0,0,1,1);
	textTimer->sprite.texture = LoadText(camera,"./src/resources/calibri.ttf","0000",87,0,13,80);
	StartT(&textTimer->timer,999999999);
}
void UpdateTextTimer(S_scene_lvl1* sc,E_camera* camera){
	G_textTimer* textTimer = &sc->textTimer;
	UpdateT(&textTimer->timer);
	int milliseconds = textTimer->timer.current-textTimer->timer.start;
	int seconds = milliseconds / 1000;
	int minutes = seconds / 60;
	int hours = minutes / 60;
	int MODmilliseconds = milliseconds%1000;
	int MODseconds = seconds % 60;
	int MODminutes = minutes % 60;
	char ichar[20];
	sprintf(ichar,"%02d:%02d:%02d:%03d",hours,MODminutes,MODseconds,MODmilliseconds);
	textTimer->sprite.texture = LoadText(camera,"./src/resources/calibri.ttf",ichar,87,0,13,80);
	EquV(&textTimer->transform.position,&camera->transform.position);
	textTimer->transform.position.y -= 900;
	SetRectText(&textTimer->sprite,&textTimer->transform,textTimer->sprite.texture);
}

void EndTextTimer(S_scene_lvl1* sc,E_input* input){
	G_textTimer* textTimer = &sc->textTimer;
	int milliseconds = textTimer->timer.current-textTimer->timer.start;
	int seconds = milliseconds / 1000;
	int minutes = seconds / 60;
	int hours = minutes / 60;
	int MODmilliseconds = milliseconds%1000;
	int MODseconds = seconds % 60;
	int MODminutes = minutes % 60;
	char ichar[20];
	sprintf(ichar,"%02d:%02d:%02d:%03d",hours,MODminutes,MODseconds,MODmilliseconds);
	int i = 9;
	printf(ichar,"%02d:%02d:%02d:%03d\n\n",hours,MODminutes,MODseconds,MODmilliseconds);
	while(strcmp(input->scores[i],ichar)<0){
		i--;
		if(i == -1){
			printf("nop");
			return;
		}
	}
	strcpy(input->scores[i],ichar);
	FILE *myFile;
	myFile = fopen("./src/resources/scores.txt", "r+");
	if (myFile == NULL){

		printf("Error Reading File\n");
		exit (0);
	}

	fprintf(myFile, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",input->scores[0],input->scores[1],input->scores[2],input->scores[3],input->scores[4]
											,input->scores[5],input->scores[6],input->scores[7],input->scores[8],input->scores[9]);
	fclose(myFile);

}

void RenderTextTimer(S_scene_lvl1* sc,E_camera* camera){

	G_textTimer* textTimer = &sc->textTimer;
	RenderGameObject(camera,&textTimer->sprite);

}
