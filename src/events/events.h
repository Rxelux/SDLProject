/*
 * input.h
 *
 *  Created on: 14 mars 2016
 *      Author: robinpelletier
 */

#ifndef EVENTS_EVENTS_H_
#define EVENTS_EVENTS_H_

#include "../header.h"

//----EVENTS-------------------------------
typedef struct
{
	int key[SDL_NUM_SCANCODES];
	int mousex,mousey;
	int mousexrel,mouseyrel;
	float mousexwheel,mouseywheel;
	char mousebuttons[8];
	char quit;
} E_input;

void UpdateEvents(E_input* in);
void InitEvents(E_input* in);

#endif /* EVENTS_EVENTS_H_ */
