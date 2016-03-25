/*
 * sprite.h
 *
 *  Created on: 25 mars 2016
 *      Author: robinpelletier
 */
#include "../header.h"
#include "../physics/physics.h"

#ifndef SPRITE_SPRITE_H_
#define SPRITE_SPRITE_H_

typedef struct{

	SDL_Texture* texture;
	SDL_Rect rect;
	P_vector pos;
}S_sprite;

#endif /* SPRITE_SPRITE_H_ */
