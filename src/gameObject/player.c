#include "player.h"

void InitPlayer(G_gameObject* player,SDL_Renderer** renderer){

	strcpy(player->name,"player");
	InitT(&player->transform,0,0,32,32);
	ToCenterSpaceV(&player->transform.position.x,&player->transform.position.y);
	InitB(&player->body,0,0,0,0,10,0.5,0.5);
	player->sprite = LoadTexture(renderer,"src/resources/Sprite.png");
	printf("%f; %f \n",player->transform.scale.x,player->transform.scale.y);
}

void UpdatePlayer(G_gameObject* player, E_input* input){

	P_vector keyForce;
	P_vector gravity;
	InitV(&keyForce,0,0);
	InitV(&gravity,0,9.81);

	MulV(&keyForce,0);
	if(input->key[SDL_SCANCODE_RIGHT])
	{
		keyForce.x = 1;
	}
	if(input->key[SDL_SCANCODE_LEFT])
	{
		keyForce.x = -1;
	}
	if(input->key[SDL_SCANCODE_DOWN])
	{
		keyForce.y = 1;
	}
	if(input->key[SDL_SCANCODE_UP])
	{
		keyForce.y = -1;
	}
	NormalizeV(&keyForce);
	MulV(&keyForce,10);
	//addV(&player->transform.position,&keyForce);
	AddFrictionB(&player->body);
	AddForceB(&player->body,&keyForce);
	AddForceB(&player->body,&gravity);
	//addForce(&player->body,&wind);
	ApplyForceB(&player->body);
	//equV(&player->body.acceleration,&keyForce);
	AddV(&player->transform.position,&player->body.velocity);

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

}
