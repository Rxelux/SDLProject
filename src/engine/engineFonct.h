/*
 * input.h
 *
 *  Created on: 14 mars 2016
 *      Author: robinpelletier
 */

#ifndef ENGINE_ENGINEFONCT_H_
#define ENGINE_ENGINEFONCT_H_

#include "engineStruct.h"

//----INPUTS-------------------------------

void UpdateEvents(E_input* in);
void InitEvents(E_input* in);

//----CAMERA----------------------------------

int InitCamera(E_camera* camera);
void RenderGameObject(E_camera* camera,S_sprite* sprite);

void ToCameraSpace(int* x,int* y,E_camera* camera);
void ToCameraSpaceFloat(float* x,float* y,E_camera* camera);
int CreateWindow(SDL_Window** window,int posX,int posY,int sizeX,int sizeY);
int CreateRenderer(SDL_Window** window,SDL_Renderer** renderer);
void SetupRenderer(SDL_Renderer** renderer,int sizeX,int sizeY);
SDL_Texture* LoadTexture(E_camera* camera, char* path);
SDL_Texture* LoadText(E_camera* camera, char* path,char* text,int R,int G,int B,int size);
void DEBUGPOINT(P_vector* point,E_camera* camera);
void DEBUGVECTOR(P_vector* start,P_vector* end,E_camera* camera,int R,int G,int B);
void DEBUGHITBOX (P_hitBox* hitBox,E_camera* camera,int R,int G,int B);

//----TIMER-------------------------------

int HasStartedT(E_timer* timer);
int HasEndedT(E_timer* timer);
int IsRunningT(E_timer* timer);
float GetProgressT(E_timer* timer);
void StartT(E_timer* timer,int duration);
void UpdateT(E_timer* timer);

//-----SPRITE----------------------------------

void SetRectSprite(S_sprite* s,P_transform* transform);
void SetRectText(S_sprite* s,P_transform* transform,SDL_Texture* texture);

#endif /* ENGINE_ENGINEFONCT_H_ */
