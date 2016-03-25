/*
 * gameObjects.h
 *
 *  Created on: 22 mars 2016
 *      Author: robinpelletier
 */


#ifndef GAMEOBJECTS_GAMEOBJECTS_H_
#define GAMEOBJECTS_GAMEOBJECTS_H_

#include "../gameEngine/gameEngine.h"
#include "../renderer/renderer.h"

//----PLAYER------------------------------------------------

void InitPlayer(G_gameEngine* ge);
void UpdatePlayer(G_gameEngine* ge);

#define GO_PLAYER 0

#endif /* GAMEOBJECTS_GAMEOBJECTS_H_ */
