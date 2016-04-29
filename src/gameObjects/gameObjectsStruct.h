/*
 * gameObjects.h
 *
 *  Created on: 22 mars 2016
 *      Author: robinpelletier
 */

#ifndef GAMEOBJECTS_GAMEOBJECTSSTRUCT_H_
#define GAMEOBJECTS_GAMEOBJECTSSTRUCT_H_

#include "../physics/physics.h"
#include "../sprite/sprite.h"

//----CAMERA----------------------------------
typedef struct{
	SDL_Window* window;						//la fenetre qui contient le jeu
	SDL_Renderer* renderer;					//le renderer qui affiche les elements du jeu dans la fenetre
	P_transform transform;					//le tranform de la camera

}G_camera;

//----PLAYER------------------------------------------------

typedef struct{
	bool active;
	P_transform transform;
	P_body body;
	S_sprite sprite;
	P_hitBox hitBox;
	P_hitBox stepHitBox;
	P_hitBox bottomHitBox;
	P_hitBox rightHitBox;
	P_hitBox leftHitBox;
	P_hitBox topHitBox;
	P_vector keyForce;
	P_vector gravity;
	P_vector jump;
	bool hitBottom;
	bool hitRight;
	bool hitLeft;
	bool hitTop;
	bool hitStep;

}G_player;

//----MAP------------------------------------------------

typedef struct{
	bool active;
	P_transform transform;
	S_sprite sprite;
	P_hitBox hitBox[1000];
	int sizeTileSetX,sizeTileSetY;
	int sizeMapX,sizeMapY;
	int tileRef[6][100000];
	SDL_Texture* sprites[6];
	P_transform paralax[6];
}G_tileMap;

//----BLOCTEST-------------------------------------------------

typedef struct{
	bool active;
	P_transform transform;
	S_sprite sprite;
	P_hitBox hitBox;
}G_blocTest;

#endif /* GAMEOBJECTS_GAMEOBJECTSSTRUCT_H_ */
