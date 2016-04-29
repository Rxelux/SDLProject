#include "gameObjectsFonct.h"

int InitCamera(S_scene_lvl1* sc){
	//crée la fenetre du jeu [renderer/initialize]
	if ( !CreateWindow(&sc->camera.window,0,0,SCREEN_WIDTH,SCREEN_HEIGHT) )
		return 0;

	//crée le renderer associé a la fenetre [renderer/initialize]
	if ( !CreateRenderer(&sc->camera.window,&sc->camera.renderer) )
		return 0;
	//met le renderer a la taille de la fenetre
	SetupRenderer(&sc->camera.renderer,SCREEN_WIDTH,SCREEN_HEIGHT);

	return 1;
}

void RenderGameObject(G_camera* camera,S_sprite* sprite){


	P_vector pos = VToCenterSpace(&sprite->dest.position);
	sprite->destrect.x = pos.x;
	sprite->destrect.y = pos.y;
	ToCameraSpace(&sprite->destrect.x,&sprite->destrect.y,camera);
	sprite->destrect.w = ceilf(sprite->destrect.w * camera->transform.scale.x);
	sprite->destrect.h = ceilf(sprite->destrect.h * camera->transform.scale.y);

	//printf("%d; %d | %d; %d \n",sprite->destrect.x,sprite->destrect.y,sprite->destrect.w,sprite->destrect.h);

	SDL_RenderCopy(camera->renderer, sprite->texture, &sprite->srcerect, &sprite->destrect);

}

void ToCameraSpace(int* x,int* y,G_camera* camera){
	*x = ceilf(*x-camera->transform.position.x)* camera->transform.scale.x + (SCREEN_WIDTH/2 * (1-camera->transform.scale.x));
	*y = ceilf(*y-camera->transform.position.y)* camera->transform.scale.y + (SCREEN_HEIGHT/2 * (1-camera->transform.scale.y));
}
void ToCameraSpaceFloat(float* x,float* y,G_camera* camera){
	*x = (*x-camera->transform.position.x)* camera->transform.scale.x + (SCREEN_WIDTH/2 * (1-camera->transform.scale.x));
	*y = (*y-camera->transform.position.y)* camera->transform.scale.y + (SCREEN_HEIGHT/2 * (1-camera->transform.scale.y));
}

int CreateWindow(SDL_Window** window,int posX,int posY,int sizeX,int sizeY)
{
	*window = SDL_CreateWindow( "Server", posX, posY, sizeX, sizeY,0 );
	if (  *window == NULL )
	{
		printf("Failed to create window : %s\n",SDL_GetError());
		return 0;
	}
	printf("window created.\n");
	return 1;
}

int CreateRenderer(SDL_Window** window,SDL_Renderer** renderer)
{
	*renderer = SDL_CreateRenderer( *window, -1, SDL_RENDERER_ACCELERATED );
	if ( *renderer == NULL )
	{
		printf("Failed to create renderer : %s\n",SDL_GetError());
		return 0;
	}
	printf("renderer created.\n");
	return 1;
}

void SetupRenderer(SDL_Renderer** renderer,int sizeX,int sizeY)
{
	// Set size of renderer to the same as window
	SDL_RenderSetLogicalSize( *renderer, sizeX, sizeY );

	// Set color of renderer to green
	SDL_SetRenderDrawColor( *renderer, 0, 255, 0, 255 );
	printf("renderer linked to window.\n");
}

SDL_Texture* LoadTexture(G_camera* camera, char* path)
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
        newTexture = SDL_CreateTextureFromSurface(camera->renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

void DEBUGHITBOX (P_hitBox* hitBox,G_camera* camera,int R,int G,int B){

	char i;
	for(i = 0;i < hitBox->nbp;i++){
		if(i !=hitBox->nbp-1){
			DEBUGVECTOR(&hitBox->tab[i],&hitBox->tab[i+1],camera,R,G,B);
		}else{
			DEBUGVECTOR(&hitBox->tab[i],&hitBox->tab[0],camera,R,G,B);
		}
	}
}

void DEBUGPOINT(P_vector* point,G_camera* camera){
	P_vector pt = VToCenterSpace(point);
	ToCameraSpaceFloat(&pt.x,&pt.y,camera);
	SDL_SetRenderDrawColor(camera->renderer, 0, 0, 0, 255);
	SDL_RenderDrawPoint(camera->renderer,pt.x+1,pt.y);
	SDL_RenderDrawPoint(camera->renderer,pt.x-1,pt.y);
	SDL_RenderDrawPoint(camera->renderer,pt.x,pt.y+1);
	SDL_RenderDrawPoint(camera->renderer,pt.x,pt.y-1);
	SDL_SetRenderDrawColor(camera->renderer, 255, 255, 255, 255);

}

void DEBUGVECTOR(P_vector* start,P_vector* end,G_camera* camera,int R,int G,int B){

	P_vector v1 = VToCenterSpace(start);
	P_vector v2 = VToCenterSpace(end);
	ToCameraSpaceFloat(&v1.x,&v1.y,camera);
	ToCameraSpaceFloat(&v2.x,&v2.y,camera);
	SDL_SetRenderDrawColor(camera->renderer, R, G, B, 255);
	SDL_RenderDrawLine(camera->renderer,v1.x,v1.y,v2.x,v2.y);
	DEBUGPOINT(start,camera);
	DEBUGPOINT(end,camera);


}
