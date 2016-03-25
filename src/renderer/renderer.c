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

void RenderGameObjects(SDL_Renderer** renderer,G_gameObject gos[MAX_OBJECTS]){

	int i;
	for(i=0;i<MAX_OBJECTS;i++){

		if (gos[i].transform.position.x <= (SCREEN_WIDTH-gos[i].transform.scale.x) && gos[i].transform.position.x >= 0){

			if (gos[i].transform.position.y <= (SCREEN_HEIGHT-gos[i].transform.scale.y) && gos[i].transform.position.y >= 0){

				SDL_Rect goRect;

				goRect.x = gos[i].transform.position.x;
				goRect.y = gos[i].transform.position.y;
				goRect.w = gos[i].transform.scale.x;
				goRect.h = gos[i].transform.scale.y;

				//DEBUG
				//printf("%d; %d | %d; %d \n",goRect.x,goRect.y,goRect.w,goRect.h);

				SDL_RenderCopy(*renderer, gos[i].sprite.texture, NULL,&goRect);
			}
		}

	}
}
