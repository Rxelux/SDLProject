/*
 * renderer.h
 *
 *  Created on: 6 mars 2016
 *      Author: robinpelletier
 */

#ifndef RENDERER_RENDERER_H_
#define RENDERER_RENDERER_H_

#include "../header.h"
#include "../gameObjects/gameObjects.h"

//--------RENDER----------
SDL_Texture* LoadTexture(SDL_Renderer** renderer, char* path);
void RenderGameObjects(SDL_Renderer** renderer,G_gameObject gos[MAX_OBJECTS]);

#endif /* RENDERER_RENDERER_H_ */
