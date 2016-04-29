/*
 * GameElements.h
 *
 *  Created on: 22 mars 2016
 *      Author: robinpelletier
 */

#ifndef SCENES_SCENESSTRUCT_H_
#define SCENES_SCENESSTRUCT_H_

#include "../events/events.h"
#include "../gameObjects/gameObjectsStruct.h"


//la structure scene definit tout ce dont nous avons besoin pour une scene de notre jeu:
//----SCENE LVL1--------------------------
typedef struct{

	E_input input;							//le E_input qui gere les entrée clavier,souris et manette pour le jeu
	G_camera camera;
	//G_gameObject gameObjects[MAX_OBJECTS];	//gameObjects un tableau de G_gameObject qui contient les elements du jeu (le joueur, la map, les scores par exemple)
	G_player player;
	G_tileMap tileMap;
	G_blocTest blocTest;
}S_scene_lvl1;

#define PLAYER_FRAME 120

//regrouper les differents elements du jeu dans cette structure permet de ne pas a avoir a passer 36 mil arguments entre les differents gameobjects, input etc

#endif /* SCENES_SCENESSTRUCT_H_ */
