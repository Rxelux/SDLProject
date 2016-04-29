#include "events.h"

void InitEvents(E_input* in){

	memset(in,0,sizeof(*in));
	in->mousexwheel = in->mouseywheel = 1;
}

void UpdateEvents(E_input* in)
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			in->key[event.key.keysym.scancode]=1;
			break;
		case SDL_KEYUP:
			in->key[event.key.keysym.scancode]=0;
			break;
		case SDL_MOUSEMOTION:
			in->mousex=event.motion.x;
			in->mousey=event.motion.y;
			in->mousexrel=event.motion.xrel;
			in->mouseyrel=event.motion.yrel;
			break;
		case SDL_MOUSEBUTTONDOWN:
			in->mousebuttons[event.button.button]=1;
			break;
		case SDL_MOUSEBUTTONUP:
			in->mousebuttons[event.button.button]=0;
			break;
		case SDL_QUIT:
			in->quit = 1;
			break;
		case SDL_MOUSEWHEEL:
			in->mousexwheel += (float)event.wheel.x/100;
			in->mousexwheel =roundf(in->mousexwheel * 100) / 100;
			in->mouseywheel += (float)event.wheel.y/100;
			in->mouseywheel = roundf(in->mouseywheel * 100) / 100;
			break;
		default:
			break;
		}
	}
}
