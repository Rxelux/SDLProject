/*
 * gameObjects.h
 *
 *  Created on: 22 mars 2016
 *      Author: robinpelletier
 */

#ifndef GAMEOBJECTS_GAMEOBJECTSFONCT_H_
#define GAMEOBJECTS_GAMEOBJECTSFONCT_H_

#include "gameObjectsStruct.h"
#include "../scenes/scenesStruct.h"

//----CAMERA----------------------------------

int InitCamera(S_scene_lvl1* sc);
void RenderGameObject(G_camera* camera,S_sprite* sprite);
void ToCameraSpace(int* x,int* y,G_camera* camera);
void ToCameraSpaceFloat(float* x,float* y,G_camera* camera);
int CreateWindow(SDL_Window** window,int posX,int posY,int sizeX,int sizeY);
int CreateRenderer(SDL_Window** window,SDL_Renderer** renderer);
void SetupRenderer(SDL_Renderer** renderer,int sizeX,int sizeY);
SDL_Texture* LoadTexture(G_camera* camera, char* path);
void DEBUGPOINT(P_vector* point,G_camera* camera);
void DEBUGVECTOR(P_vector* start,P_vector* end,G_camera* camera,int R,int G,int B);
void DEBUGHITBOX (P_hitBox* hitBox,G_camera* camera,int R,int G,int B);

//----PLAYER------------------------------------------------

void InitPlayer(S_scene_lvl1* sc);
void UpdatePlayer(S_scene_lvl1* sc);
void RenderPlayer(S_scene_lvl1* sc);
bool TestCollisionMap(G_player* player,P_vector* posTest,P_hitBox* hitBox,G_tileMap* tileMap,int pX,int mX,int pY,int mY);
//----MAP------------------------------------------------

void InitTileMap(S_scene_lvl1* sc);
void UpdateTileMap(S_scene_lvl1* sc);
void RenderTileMap(S_scene_lvl1* sc,int j);
P_vector GetMapPos(P_vector* v,G_tileMap* tileMap);

//----BLOCTEST----------------------

void InitBlocTest(S_scene_lvl1* sc);
void RenderBlocTest(S_scene_lvl1* sc);
#endif /* GAMEOBJECTS_GAMEOBJECTSFONCT_H_ */
