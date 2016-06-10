/*
 * input.h
 *
 *  Created on: 14 mars 2016
 *      Author: robinpelletier
 */

#ifndef ENGINE_ENGINESTRUCT_H_
#define ENGINE_ENGINESTRUCT_H_

#include "../header.h"
#include "../physics/physics.h"

//----INPUTS-------------------------------
typedef struct
{
	int scene;
	int key[SDL_NUM_SCANCODES];
	int lastKeyPress;
	int mousex,mousey;
	int mousexrel,mouseyrel;
	float mousexwheel,mouseywheel;
	char mousebuttons[8];
	char quit;

	int up;
	int down;
	int left;
	int right;
	int select;
	int musicVol;
	int soundVol;
	char scores[10][20];
} E_input;

//----CAMERA----------------------------------
typedef struct{
	SDL_Window* window;						//la fenetre qui contient le jeu
	SDL_Renderer* renderer;					//le renderer qui affiche les elements du jeu dans la fenetre
	P_transform transform;					//le tranform de la camera

}E_camera;

//----TIMER-------------------------------
typedef struct{
	int initTime;
	int start;
	int end;
	int current;
	bool loop;
	bool pingPong;

}E_timer;

//-----SPRITE----------------------------------
typedef struct{

	SDL_Texture* texture;
	SDL_Rect srcerect;
	SDL_Rect destrect;
	P_transform srce;
	P_transform dest;
	unsigned int frameTime;
}S_sprite;

typedef struct{
	P_transform transform;
	S_sprite sprite;
	bool hover;
}E_button;

#endif /* ENGINE_ENGINESTRUCT_H_ */
