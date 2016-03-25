/*
 * GameElements.h
 *
 *  Created on: 22 mars 2016
 *      Author: robinpelletier
 */

#ifndef GAMEOBJECT_GAMEENGINE_H_
#define GAMEOBJECT_GAMEENGINE_H_

#include "../gameObject/gameObject.h"
#include "../events/events.h"
#include "initializer.h"

//la structure G_gameEngine definit tout ce dont nous avons besoin pour notre jeu:
typedef struct{

	SDL_Window* window;						//la fenetre qui contient le jeu
	SDL_Renderer* renderer;					//le renderer qui affiche les elements du jeu dans la fenetre
	E_input input;							//le E_input qui gere les entrée clavier,souris et manette pour le jeu
	G_gameObject gameObjects[MAX_OBJECTS];	//gameObjects un tableau de G_gameObject qui contient les elements du jeu (le joueur, la map, les scores par exemple)
}G_gameEngine;

//regrouper les differents elements du jeu dans cette structure permet de ne pas a avoir a passer 36 mil arguments entre les differents gameobjects, input et renderer

#endif /* GAMEOBJECT_GAMEENGINE_H_ */
