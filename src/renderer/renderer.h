/*
 * renderer.h
 *
 *  Created on: 6 mars 2016
 *      Author: robinpelletier
 */

#ifndef RENDERER_RENDERER_H_
#define RENDERER_RENDERER_H_

#include "../header.h"
#include "../gameObject/gameObject.h"

//----Init--------------------
int InitAllSDL();
int InitSDL();
int InitSDL_image();
int InitSDL_ttf();
int InitSDL_mixer();
int CreateWindow(SDL_Window** window,int posX,int posY,int sizeX,int sizeY);
int CreateRenderer(SDL_Window** window,SDL_Renderer** renderer);
void SetupRenderer(SDL_Renderer** renderer,int sizeX,int sizeY);

//--------RENDER----------
SDL_Texture* LoadTexture(SDL_Renderer** renderer, char* path);
void RenderGameObject(SDL_Renderer** renderer, G_gameObject* go);

#endif /* RENDERER_RENDERER_H_ */
