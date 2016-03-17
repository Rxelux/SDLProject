#include "renderer.h"

SDL_Texture* LoadTexture(SDL_Renderer** renderer, char* path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path);
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( *renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

void RenderGameObject(SDL_Renderer** renderer, G_gameObject* go){

	if (go->transform.position.x <= (SCREEN_WIDTH-go->transform.scale.x) && go->transform.position.x >= 0){

		if (go->transform.position.y <= (SCREEN_HEIGHT-go->transform.scale.y) && go->transform.position.y >= 0){

			SDL_Rect goRect;

			goRect.x = go->transform.position.x;
			goRect.y = go->transform.position.y;
			goRect.w = go->transform.scale.x;
			goRect.h = go->transform.scale.y;

			//DEBUG
			//printf("%d; %d | %d; %d \n",goRect.x,goRect.y,goRect.w,goRect.h);

			SDL_RenderCopy(*renderer, go->sprite, NULL,&goRect);
		}
	}
}
