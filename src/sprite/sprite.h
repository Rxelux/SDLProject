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
	SDL_Rect srcerect;
	SDL_Rect destrect;
	P_transform srce;
	P_transform dest;
	unsigned int frameTime;
}S_sprite;

void SetSrceRect(S_sprite* s,P_transform* transform);

#endif /* SPRITE_SPRITE_H_ */
