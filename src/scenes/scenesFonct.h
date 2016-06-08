/*
 * GameElements.h
 *
 *  Created on: 22 mars 2016
 *      Author: robinpelletier
 */

#ifndef SCENES_SCENESFONCT_H_
#define SCENES_SCENESFONCT_H_

#include "scenesStruct.h"

int InitScene_lvl1(S_scene_lvl1* sc,E_camera* camera);
int UpdateScene_lvl1(S_scene_lvl1* sc,E_input* input,E_camera* camera);

int InitScene_menu(S_scene_menu* sc,E_input* input,E_camera* camera);
int UpdateScene_menu(S_scene_menu* sc,E_input* input,E_camera* camera);

int InitScene_map(S_scene_map* sc,E_camera* camera);
int UpdateScene_map(S_scene_map* sc,E_input* input,E_camera* camera);

int InitScene_cutscene(S_scene_cutscene* sc,E_camera* camera);
int UpdateScene_cutscene(S_scene_cutscene* sc,E_input* input,E_camera* camera);
#endif /* SCENES_SCENESFONCT_H_ */
