/*
 * gameObjects.h
 *
 *  Created on: 22 mars 2016
 *      Author: robinpelletier
 */

#ifndef GAMEOBJECTS_GAMEOBJECTSSTRUCT_H_
#define GAMEOBJECTS_GAMEOBJECTSSTRUCT_H_

#include "../engine/engineStruct.h"
#include "../engine/engineFonct.h"

//----PLAYER------------------------------------------------

typedef struct{
	bool active;
	P_transform transform;
	P_body body;
	S_sprite sprite;
	P_hitBox hitBox;
	P_hitBox stepHitBox;
	P_hitBox bottomHitBox;
	P_hitBox rightHitBox;
	P_hitBox leftHitBox;
	P_hitBox topHitBox;
	P_vector keyForce;
	P_vector gravity;
	P_vector jump;
	P_vector fly;
	bool hitBottom;
	bool hitRight;
	bool hitLeft;
	bool hitTop;
	bool hitStep;
	int maxJumpTime;
	int minJumpTime;
	int jumpTime;
	int power;
	Mix_Chunk* walkSound;
	Mix_Chunk* jumpSound;
	Mix_Chunk* powerupSound;
	Mix_Chunk* wind;

}G_player;

typedef struct{
	bool active;
	P_transform transform;
	S_sprite sprite;
	S_sprite sprite2;

}G_scarf;

//----MAP------------------------------------------------

typedef struct{
	bool active;
	P_transform transform;
	S_sprite sprite;
	P_hitBox hitBox[1000];
	int sizeTileSetX,sizeTileSetY;
	int sizeMapX,sizeMapY;
	int tileRef[5][100000];
	SDL_Texture* sprites[5];
	P_transform paralax[5];
}G_tileMap;

typedef struct{
	bool active;
	E_timer timer;
	P_transform transform;
	S_sprite sprite;
}G_textTimer;

//----menuBG-------------------------------------------------

typedef struct{
	bool active;
	P_transform transform;
	S_sprite sprite;
	Mix_Music *BGMusic;

}G_menuBG;

//----textMenu-------------------------------------------------

typedef struct{
	bool active;
	P_transform transform;
	S_sprite sprite;
	P_vector pos[4];
	SDL_Texture* sprites[4];

}G_textMenu;

typedef struct{
	bool active;
	P_transform transform;
	S_sprite sprite;
	P_vector pos[10];
	SDL_Texture* sprites[10];

}G_textCredits;

typedef struct{
	bool active;
	P_transform transform;
	S_sprite sprite;
	P_vector pos[10];
	SDL_Texture* sprites[10];

}G_textScores;
//----buttonMenu-----------------

typedef struct{
	bool active;
	E_button buttons[4];
	Mix_Chunk *ButtonSound;
	Mix_Chunk *ButtonSoundValid;

}G_buttonsMenu;

typedef struct{
	bool active;
	E_button buttons[10];
	Mix_Chunk *ButtonSound;
	Mix_Chunk *ButtonSoundValid;
	int into;


}G_buttonsOption;

//----buttonMap-----------------

typedef struct{
	P_transform transform;
	bool active;
	S_sprite sprite;
	E_button buttons[5];
	Mix_Chunk *ButtonSound;
	Mix_Chunk *ButtonSoundValid;

}G_buttonsMap;

//----mapBG-------------------------------------------------

typedef struct{
	bool active;
	P_transform transform;
	S_sprite sprite;

}G_mapBG;

//----cutsceneBG-------------------------------------------------

typedef struct{
	bool active;
	P_transform transform;
	P_vector dest;
	S_sprite sprite;

}G_cutscene;

#endif /* GAMEOBJECTS_GAMEOBJECTSSTRUCT_H_ */
