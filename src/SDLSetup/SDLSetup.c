#include "SDLSetup.h"

int InitAllSDL()
{
	if ( !InitSDL() )
		return 0;

	if ( !InitSDL_image() )
		return 0;

	if ( !InitSDL_ttf() )
		return 0;

	if ( !InitSDL_mixer() )
		return 0;
	return 1;
}

int InitSDL()
{
	if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		printf("Failed to initialize SDL : %s\n",SDL_GetError());
		return 0;
	}
	printf("SDL Initialisation complete. \n");
	return 1;
}
int InitSDL_image(){
	//Initialisation du chargement des images png avec SDL_Image 2
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		printf( "SDL_image n'a pu être initialisée! SDL_image Error: %s\n", IMG_GetError() );
		return 0;
	}
	printf("SDL_image Initialisation complete. \n");
	return 1;
}
int InitSDL_ttf(){
	//On initialise SDL_TTF 2 qui gérera l'écriture de texte
	if (TTF_Init() < 0)
	{
		printf("Impossible d'initialiser SDL TTF: %s\n", TTF_GetError());
		return 0;
	}
	printf("SDL_TTF Initialisation complete. \n");
	return 1;
}
int InitSDL_mixer(){
	//On initialise SDL_Mixer 2, qui gérera la musique et les effets sonores
	int flags = MIX_INIT_MP3;
	int initted = Mix_Init(flags);
	if ((initted & flags) != flags)
	{
		printf("Mix_Init: Failed to init SDL_Mixer\n");
		printf("Mix_Init: %s\n", Mix_GetError());
		return 0;
	}
	printf("SDL_Mixer Initialisation complete. \n");
	/* Open 44.1KHz, signed 16bit, system byte order,
	stereo audio, using 1024 byte chunks (voir la doc pour plus d'infos) */
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
		return 0;
	}
	printf("Mix_OpenAudio Initialisation complete. \n");
	// Définit le nombre de pistes audio (channels) à mixer
	Mix_AllocateChannels(32);
	return 1;
}


