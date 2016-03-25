#include "initializer.h"

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
		fprintf(stdout,"Failed to initialize SDL :",SDL_GetError());
		return 0;
	}
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
	return 1;
}
int InitSDL_ttf(){
	//On initialise SDL_TTF 2 qui gérera l'écriture de texte
	if (TTF_Init() < 0)
	{
		printf("Impossible d'initialiser SDL TTF: %s\n", TTF_GetError());
		return 0;
	}
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
	/* Open 44.1KHz, signed 16bit, system byte order,
	stereo audio, using 1024 byte chunks (voir la doc pour plus d'infos) */
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
		return 0;
	}

	// Définit le nombre de pistes audio (channels) à mixer
	Mix_AllocateChannels(32);
	return 1;
}

int CreateWindow(SDL_Window** window,int posX,int posY,int sizeX,int sizeY)
{
	*window = SDL_CreateWindow( "Server", posX, posY, sizeX, sizeY,0 );
	fprintf(stdout,SDL_GetError());
	if (  *window == NULL )
	{
		fprintf(stdout,"Failed to create window :",SDL_GetError());
		return 0;
	}

	return 1;
}
int CreateRenderer(SDL_Window** window,SDL_Renderer** renderer)
{
	*renderer = SDL_CreateRenderer( *window, -1, 0 );
	fprintf(stdout,SDL_GetError());
	if ( *renderer == NULL )
	{
		fprintf(stdout,"Failed to create renderer :",SDL_GetError());
		return 0;
	}

	return 1;
}
void SetupRenderer(SDL_Renderer** renderer,int sizeX,int sizeY)
{
	// Set size of renderer to the same as window
	SDL_RenderSetLogicalSize( *renderer, sizeX, sizeY );

	// Set color of renderer to green
	SDL_SetRenderDrawColor( *renderer, 0, 255, 0, 255 );
}

