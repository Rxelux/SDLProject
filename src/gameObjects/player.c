#include "gameObjects.h"

void InitPlayer(G_gameEngine* ge){

	G_gameObject* player = &ge->gameObjects[GO_PLAYER];

	strcpy(player->name,"player");
	InitT(&player->transform,0,0,32,32);
	ToCenterSpaceV(&player->transform.position.x,&player->transform.position.y);
	InitB(&player->body,0,0,0,0,10,0.5,0.5);
	player->sprite.texture = LoadTexture(&ge->renderer,"src/resources/Sprite.png");
	//printf("%f; %f \n",player->transform.scale.x,player->transform.scale.y);
}

void UpdatePlayer(G_gameEngine* ge){

	G_gameObject* player = &ge->gameObjects[GO_PLAYER];
	P_vector keyForce;
	P_vector gravity;
	P_vector jump;
	int grounded = 0;
	InitV(&keyForce,0,0);
	InitV(&gravity,0,9.81);
	InitV(&jump,0,-200);

	MulV(&keyForce,0);
	if(ge->input.key[SDL_SCANCODE_RIGHT])
	{
		keyForce.x = 1;
	}
	if(ge->input.key[SDL_SCANCODE_LEFT])
	{
		keyForce.x = -1;
	}
	if(ge->input.key[SDL_SCANCODE_DOWN])
	{
		keyForce.y = 1;
	}
	if (player->transform.position.y < 512 && player->transform.position.y > 510-player->transform.scale.y) grounded = 1;

	if(ge->input.key[SDL_SCANCODE_UP] && grounded)
	{
		AddForceB(&player->body,&jump);
		printf("%d \n",grounded);
	}

	grounded = 0;

	NormalizeV(&keyForce);
	MulV(&keyForce,10);

	AddFrictionB(&player->body);
	AddForceB(&player->body,&keyForce);
	AddForceB(&player->body,&gravity);

	ApplyForceB(&player->body);

	AddV(&player->transform.position,&player->body.velocity);



	//provisoire pour grounded

	if (player->transform.position.x > (SCREEN_WIDTH-player->transform.scale.x) && player->body.velocity.x > 0){
		player->body.velocity.x *= -1*player->body.coefBounciness;
		player->transform.position.x = SCREEN_WIDTH-player->transform.scale.x;
	}
	if (player->transform.position.x < 0 && player->body.velocity.x < 0){
		player->body.velocity.x *= -1*player->body.coefBounciness;
		player->transform.position.x = 0;
	}
	if (player->transform.position.y > (SCREEN_HEIGHT-player->transform.scale.y) && player->body.velocity.y > 0){
		player->body.velocity.y *= -1*player->body.coefBounciness;
		player->transform.position.y = SCREEN_HEIGHT-player->transform.scale.y;
	}
	if (player->transform.position.y < 0 && player->body.velocity.y < 0){
		player->body.velocity.y *= -1*player->body.coefBounciness;
		player->transform.position.y = 0;
	}

	//printf("%f; %f \n",player->transform.position.x,player->transform.position.y);
}
