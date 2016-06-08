/*
 * GameElements.h
 *
 *  Created on: 22 mars 2016
 *      Author: robinpelletier
 */

#ifndef SCENES_SCENESSTRUCT_H_
#define SCENES_SCENESSTRUCT_H_

#include "../gameObjects/gameObjectsStruct.h"


//la structure scene definit tout ce dont nous avons besoin pour une scene de notre jeu:
//----SCENE LVL1--------------------------
typedef struct{

	G_player player;
	G_scarf scarf;
	G_tileMap tileMap;
	G_menuBG menuBG;

}S_scene_lvl1;

typedef struct{
	G_menuBG menuBG;
	G_textMenu textMenu;
	G_textCredits textCredits;
	G_buttonsMenu bm;
	G_buttonsOption bo;

}S_scene_menu;

typedef struct{
	G_mapBG mapBG;
	G_buttonsMap bm;

}S_scene_map;

typedef struct{
	G_cutscene ctsBG;

}S_scene_cutscene;

#define PLAYER_FRAME 120

//regrouper les differents elements du jeu dans cette structure permet de ne pas a avoir a passer 36 mil arguments entre les differents gameobjects, input etc

#endif /* SCENES_SCENESSTRUCT_H_ */
