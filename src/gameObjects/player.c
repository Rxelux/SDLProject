#include "gameObjectsFonct.h"

void InitPlayer(S_scene_lvl1* sc){

	G_player* player = &sc->player;

	player->active = 1;
	InitH(&player->hitBox,8,15,8,-15,-8,-15,-8,15,0,0,0,0,4);
	InitH(&player->stepHitBox,9,12,9,15,-9,15,-9,12,0,0,0,0,4);
	InitH(&player->bottomHitBox,8,14,8,16,-8,16,-8,14,0,0,0,0,4);
	InitH(&player->topHitBox,7,-14,7,-16,-7,-16,-7,-14,0,0,0,0,4);
	InitH(&player->rightHitBox,7,-14,9,-14,9,10,7,10,0,0,0,0,4);
	InitH(&player->leftHitBox,-7,-14,-9,-14,-9,10,-7,10,0,0,0,0,4);
	InitT(&player->transform,-800,-40,10,10);
	InitB(&player->body,0,0,0,0,10,0.2,0.5);
	InitT(&player->sprite.srce,0,0,32,32);
	InitT(&player->sprite.dest,0,0,32,32);
	player->sprite.texture = LoadTexture(&sc->camera,"src/resources/IdleSheet.png");
	player->sprite.frameTime = 0;

	InitV(&player->keyForce,0,0);
	InitV(&player->gravity,0,9.81);
	InitV(&player->jump,0,-100);

}

void UpdatePlayer(S_scene_lvl1* sc){

	sc->camera.transform.scale.x = sc->input.mouseywheel;
	sc->camera.transform.scale.y = sc->input.mouseywheel;

	G_player* player = &sc->player;
	player->hitBottom = TestCollisionMap(player,&player->transform.position,&player->bottomHitBox,&sc->tileMap,-2,+2,-3,+3);
	player->hitRight = TestCollisionMap(player,&player->transform.position,&player->rightHitBox,&sc->tileMap,-2,+2,-3,+3);
	player->hitLeft = TestCollisionMap(player,&player->transform.position,&player->leftHitBox,&sc->tileMap,-2,+2,-3,+3);
	player->hitTop = TestCollisionMap(player,&player->transform.position,&player->topHitBox,&sc->tileMap,-2,+2,-3,+3);
	player->hitStep = TestCollisionMap(player,&player->transform.position,&player->stepHitBox,&sc->tileMap,-2,+2,-3,+3);
	//printf("grounded %d \n",player->grounded);

	//---------input_controle du joueur---------------
	MulV(&player->keyForce,0);
	bool jump = false;
	if(!player->hitTop && sc->input.key[SDL_SCANCODE_W]){ //z
		jump = true;
	}
	if(!player->hitBottom && sc->input.key[SDL_SCANCODE_S]){ //s
		player->keyForce.y += 1;
	}
	if(!player->hitLeft && sc->input.key[SDL_SCANCODE_A]){ //q
		player->keyForce.x -= 1;
	}
	if(!player->hitRight && sc->input.key[SDL_SCANCODE_D]){ //d
		player->keyForce.x += 1;
	}
	if(player->hitStep && player->hitBottom && !player->hitRight && !player->hitLeft){
		player->keyForce.y -= 2*fabsf(player->keyForce.x);
	}

	//--------calcul du deplacement---------
	//NormalizeV(&player->keyForce);
	MulV(&player->keyForce,10);

	AddFrictionB(&player->body);
	if(!player->hitBottom){
		AddForceB(&player->body,&player->gravity);
	}else{
		if(jump && !player->hitRight && !player->hitLeft){
			AddForceB(&player->body,&player->jump);
		}
	}
	AddForceB(&player->body,&player->keyForce);
	ApplyForceB(&player->body);

	/*une fois la veloc calculée on teste si apres deplacement on touche qqch
	  il faut donc obtenir une copie de la position future et tester si on peut s'y deplacer*/

	//----test collision map------
	P_vector velTest = VEqu(&player->body.velocity);
	P_vector posTest = VAdd(&player->transform.position,&velTest);


	bool collide = false;
	collide = TestCollisionMap(player,&posTest,&player->hitBox,&sc->tileMap,-2,+2,-2,+2);

	if(!collide){
		printf("no col %f; %f \n",player->body.velocity.x,player->body.velocity.y);
		AddV(&player->transform.position,&velTest);
	}else{
		int i,j;
		for(j = 0;j < 2;j++){
			for(i = 0;i < 10;i++){//se raprocher du point de collision par dichotomie
				if(collide){
					MulV(&velTest,0.5);
				}else{
					MulV(&velTest,1.5);
				}
				posTest = VAdd(&player->transform.position,&velTest);
				collide = TestCollisionMap(player,&posTest,&player->hitBox,&sc->tileMap,-2,+2,-2,+2);
			}
			if(collide){
				MulV(&velTest,0.5);
			}
			P_hitBox hb = HMatchPS(&player->hitBox,&posTest,&player->transform.scale);
			DEBUGHITBOX(&hb,&sc->camera,128,0,0);
			AddV(&player->transform.position,&velTest);

			player->hitBottom = TestCollisionMap(player,&player->transform.position,&player->bottomHitBox,&sc->tileMap,-2,+2,-3,+3);
			player->hitRight = TestCollisionMap(player,&player->transform.position,&player->rightHitBox,&sc->tileMap,-2,+2,-3,+3);
			player->hitLeft = TestCollisionMap(player,&player->transform.position,&player->leftHitBox,&sc->tileMap,-2,+2,-3,+3);
			player->hitTop = TestCollisionMap(player,&player->transform.position,&player->topHitBox,&sc->tileMap,-2,+2,-3,+3);

			if(player->hitTop && player->body.velocity.y<0) {
				player->body.velocity.y=0;
			}
			if(player->hitBottom && player->body.velocity.y>0){
				player->body.velocity.y=0;
			}
			if(player->hitLeft && player->body.velocity.x<0) {
				player->body.velocity.x=0;
			}
			if(player->hitRight && player->body.velocity.x>0){
				player->body.velocity.x=0;
			}
			printf("col %f; %f \n",player->body.velocity.x,player->body.velocity.y);
		}
	}

	if(DistanceV(&player->transform.position,&sc->camera.transform.position)>10){
		LerpV(&sc->camera.transform.position,&player->transform.position,DistanceV(&player->transform.position,&sc->camera.transform.position)/100);
	}

	//test texture rect thingy
	int currentTime = SDL_GetTicks();

	if(currentTime - player->sprite.frameTime > PLAYER_FRAME){

		player->sprite.srce.position.x++;
		if(player->sprite.srce.position.x > 3){
			player->sprite.srce.position.x = 0;
			player->sprite.srce.position.y++;
		}
		if(player->sprite.srce.position.y > 2){
			player->sprite.srce.position.x = 0;
			player->sprite.srce.position.y = 0;
		}

		player->sprite.frameTime = currentTime;
	}
	SetSrceRect(&player->sprite,&player->transform);
	//printf("%f , %f \n",player->sprite.pos.x,player->sprite.pos.y);
	//printf("%f; %f \n",player->transform.position.x,player->transform.position.y);
	//printf("%f; %f \n",player->body.velocity.x,player->body.velocity.y);
	//printf("%f; %f \n",sc->camera.transform.position.x,sc->camera.transform.position.y);
	//printf("%f,%f \n",GetMapPos(&player->transform.position,&sc->tileMap).x,GetMapPos(&player->transform.position,&sc->tileMap).y);

}

bool TestCollisionMap(G_player* player,P_vector* posTest,P_hitBox* hitBox,G_tileMap* tileMap,int pX,int mX,int pY,int mY){
	//----test collision map------
	P_hitBox hb = HMatchPS(hitBox,posTest,&player->transform.scale);
	int px = GetMapPos(posTest,tileMap).x;
	int py = GetMapPos(posTest,tileMap).y;
	int i,j,k;
	bool collision = false;
	for(i = px+pX;i<px+mX;i++){
		for(j = py+pY;j<py+mY;j++){
			if(!collision){
				k = i+j*tileMap->sizeMapX;
				P_vector mapPos = VInit((i*tileMap->sprite.dest.scale.x - tileMap->sizeMapX*tileMap->sprite.dest.scale.x/2)*tileMap->transform.scale.x,
						(j*tileMap->sprite.dest.scale.y- tileMap->sizeMapY*tileMap->sprite.dest.scale.y/2)*tileMap->transform.scale.x);
				P_hitBox hbmap = HMatchPS(&tileMap->hitBox[tileMap->tileRef[3][k]],&mapPos,&tileMap->transform.scale);
				collision = CollisionAB(&hbmap,&hb);
				//printf("\t collision : %d \n",collision);
				if(collision)return true;
			}
		}
	}
	return false;
}

void RenderPlayer(S_scene_lvl1* sc){

	G_player* player = &sc->player;
	P_hitBox hb = HMatchT(&player->hitBox,&player->transform);
	RenderGameObject(&sc->camera,&player->sprite);
	DEBUGHITBOX(&hb,&sc->camera,128,255,0);
	hb = HMatchT(&player->bottomHitBox,&player->transform);
	DEBUGHITBOX(&hb,&sc->camera,0,128,255);
	hb = HMatchT(&player->topHitBox,&player->transform);
	DEBUGHITBOX(&hb,&sc->camera,255,0,128);
	hb = HMatchT(&player->leftHitBox,&player->transform);
	DEBUGHITBOX(&hb,&sc->camera,128,0,255);
	hb = HMatchT(&player->rightHitBox,&player->transform);
	DEBUGHITBOX(&hb,&sc->camera,255,128,0);
	hb = HMatchT(&player->stepHitBox,&player->transform);
	DEBUGHITBOX(&hb,&sc->camera,0,255,128);

}
