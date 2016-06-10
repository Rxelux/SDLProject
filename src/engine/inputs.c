#include "engineFonct.h"

void InitEvents(E_input* in){

	memset(in,0,sizeof(*in));
	in->scene = 0;
	FILE *myFile;
		myFile = fopen("./src/resources/scores.txt", "r");
		if (myFile == NULL){

			printf("Error Reading File\n");
			exit (0);
		}

	int i;
	for(i = 0;i < 10;i++){
		fscanf(myFile, "%[^,],",in->scores[i]);
	}

	fclose(myFile);

	myFile = fopen("./src/resources/save.txt", "r");
	if (myFile == NULL){

		printf("Error Reading File\n");
		exit (0);
	}

	fscanf(myFile, "%d,",&in->up);
	fscanf(myFile, "%d,",&in->down);
	fscanf(myFile, "%d,",&in->left);
	fscanf(myFile, "%d,",&in->right);
	fscanf(myFile, "%d,",&in->select);
	fscanf(myFile, "%d,",&in->musicVol);
	fscanf(myFile, "%d,",&in->soundVol);

	fclose(myFile);
}

void UpdateEvents(E_input* in)
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			in->key[event.key.keysym.scancode]=1;
			in->lastKeyPress = event.key.keysym.scancode;
			break;
		case SDL_KEYUP:
			in->key[event.key.keysym.scancode]=0;
			break;
		case SDL_MOUSEMOTION:
			in->mousex=event.motion.x;
			in->mousey=event.motion.y;
			in->mousexrel=event.motion.xrel;
			in->mouseyrel=event.motion.yrel;
			break;
		case SDL_MOUSEBUTTONDOWN:
			in->mousebuttons[event.button.button]=1;
			break;
		case SDL_MOUSEBUTTONUP:
			in->mousebuttons[event.button.button]=0;
			break;
		case SDL_QUIT:
			in->quit = 1;
			break;
		case SDL_MOUSEWHEEL:
			in->mousexwheel += (float)event.wheel.x/100;
			in->mousexwheel =roundf(in->mousexwheel * 100) / 100;
			in->mouseywheel += (float)event.wheel.y/100;
			in->mouseywheel = roundf(in->mouseywheel * 100) / 100;
			break;
		default:
			break;
		}
	}
}
