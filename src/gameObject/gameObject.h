/*
 * gameObject.h
 *
 *  Created on: 16 mars 2016
 *      Author: robinpelletier
 */

#ifndef GAMEOBJECT_GAMEOBJECT_H_
#define GAMEOBJECT_GAMEOBJECT_H_

#include "../header.h"
#include "../physics/physics.h"



//----GAMEOBJECT--------------------------------------------
typedef struct{
	char name[10];
	P_transform transform;
	P_body body;
	SDL_Texture* sprite;
}G_gameObject;

#endif /* GAMEOBJECT_GAMEOBJECT_H_ */
