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
#include "../events/events.h"


//----GAMEOBJECT--------------------------------------------
typedef struct{
	char name[10];
	P_transform transform;
	P_body body;
}G_gameObject;

//----PLAYER------------------------------------------------

void InitPlayer(G_gameObject* player);
void UpdatePlayer(G_gameObject* player, E_input* input);

#endif /* GAMEOBJECT_GAMEOBJECT_H_ */
