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
#include "../sprite/sprite.h"

//----GAMEOBJECT--------------------------------------------
typedef struct{
	char name[10];
	P_transform transform;
	P_body body;
	S_sprite sprite;
	int active;
}G_gameObject;

#endif /* GAMEOBJECT_GAMEOBJECT_H_ */
