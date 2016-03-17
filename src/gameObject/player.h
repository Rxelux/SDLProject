/*
 * player.h
 *
 *  Created on: 17 mars 2016
 *      Author: robinpelletier
 */

#ifndef GAMEOBJECT_PLAYER_H_
#define GAMEOBJECT_PLAYER_H_

#include "gameObject.h"
#include "../events/events.h"
#include "../renderer/renderer.h"

//----PLAYER------------------------------------------------

void InitPlayer(G_gameObject* player,SDL_Renderer** renderer);
void UpdatePlayer(G_gameObject* player, E_input* input);

#endif /* GAMEOBJECT_PLAYER_H_ */
