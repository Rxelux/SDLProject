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

//----PLAYER------------------------------------------------

void InitPlayer(S_scene_lvl1* sc,E_camera* camera);
void UpdatePlayer(S_scene_lvl1* sc,E_input* input,E_camera* camera);
void RenderPlayer(S_scene_lvl1* sc,E_camera* camera);

void InitScarf(S_scene_lvl1* sc,E_camera* camera);
void UpdateScarf(S_scene_lvl1* sc,E_camera* camera);
void RenderScarf(S_scene_lvl1* sc,E_camera* camera);

bool TestCollisionMap(G_player* player,P_vector* posTest,P_hitBox* hitBox,G_tileMap* tileMap,int pX,int mX,int pY,int mY);
//----TileMAP------------------------------------------------

void InitTileMap(S_scene_lvl1* sc,E_camera* camera);
void UpdateTileMap(S_scene_lvl1* sc,E_camera* camera);
void RenderTileMap(S_scene_lvl1* sc,E_input* input,E_camera* camera,int j);

P_vector GetMapPos(P_vector* v,G_tileMap* tileMap);

void InitTextTimer(S_scene_lvl1* sc,E_camera* camera);
void UpdateTextTimer(S_scene_lvl1* sc,E_camera* camera);
void RenderTextTimer(S_scene_lvl1* sc,E_camera* camera);

void EndTextTimer(S_scene_lvl1* sc,E_input* input);

//----MenuBG--------------------------------------------------

void InitMenuBG(S_scene_menu* sc,E_camera* camera);
void InitLvl1BG(S_scene_lvl1* sc,E_camera* camera);
void UpdateLvl1BG(S_scene_lvl1* sc,E_camera* camera);
void RenderMenuBG(S_scene_menu* sc,E_camera* camera);
void RenderLvl1BG(S_scene_lvl1* sc,E_camera* camera);

//----textMenu--------------------------------------------------

void InitTextMenu(S_scene_menu* sc,E_camera* camera);
void RenderTextMenu(S_scene_menu* sc,E_camera* camera);

void InitTextCredits(S_scene_menu* sc,E_camera* camera);
void UpdateTextCredits(S_scene_menu* sc,E_input* input,E_camera* camera);
void RenderTextCredits(S_scene_menu* sc,E_camera* camera);

void InitTextScores(S_scene_menu* sc,E_input* input,E_camera* camera);
void UpdateTextScores(S_scene_menu* sc,E_input* input,E_camera* camera);
void RenderTextScores(S_scene_menu* sc,E_camera* camera);
//----ButtonsMenu--------------------------------------------------

void InitButtonsMenu(S_scene_menu* sc,E_camera* camera);
void UpdateButtonsMenu(S_scene_menu* sc,E_input* input,E_camera* camera);
void RenderButtonsMenu(S_scene_menu* sc,E_camera* camera);

void InitButtonsOption(S_scene_menu* sc,E_input* input,E_camera* camera);
void UpdateButtonsOption(S_scene_menu* sc,E_input* input,E_camera* camera);
void RenderButtonsOption(S_scene_menu* sc,E_camera* camera);
bool testKey(E_input* input,int key);

//----MapBG--------------------------------------------------

void InitMapBG(S_scene_map* sc,E_camera* camera);
void RenderMapBG(S_scene_map* sc,E_camera* camera);

//----ButtonsMap--------------------------------------------------

void InitButtonsMap(S_scene_map* sc,E_camera* camera);
void UpdateButtonsMap(S_scene_map* sc,E_input* input,E_camera* camera);
void RenderButtonsMap(S_scene_map* sc,E_camera* camera);

#endif /* GAMEOBJECTS_GAMEOBJECTSFONCT_H_ */
