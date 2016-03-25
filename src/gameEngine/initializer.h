/*
 * initializer.h
 *
 *  Created on: 22 mars 2016
 *      Author: robinpelletier
 */

#ifndef RENDERER_INITIALIZER_H_
#define RENDERER_INITIALIZER_H_

#include "../header.h"

//----Init--------------------
int InitAllSDL();
int InitSDL();
int InitSDL_image();
int InitSDL_ttf();
int InitSDL_mixer();
int CreateWindow(SDL_Window** window,int posX,int posY,int sizeX,int sizeY);
int CreateRenderer(SDL_Window** window,SDL_Renderer** renderer);
void SetupRenderer(SDL_Renderer** renderer,int sizeX,int sizeY);

#endif /* RENDERER_INITIALIZER_H_ */
