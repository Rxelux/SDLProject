#include "gameObjectsFonct.h"

void InitPlayer(S_scene_lvl1* sc,E_camera* camera){

	G_player* player = &sc->player;

	player->active = 1;
	InitH(&player->hitBox,8,15,8,-15,-8,-15,-8,15,0,0,0,0,4);
	InitH(&player->stepHitBox,9,14,9,15,-9,15,-9,14,0,0,0,0,4);
	InitH(&player->bottomHitBox,8,14,8,16,-8,16,-8,14,0,0,0,0,4);
	InitH(&player->topHitBox,8,-14,8,-16,-8,-16,-8,-14,0,0,0,0,4);
	InitH(&player->rightHitBox,7,-15,9,-15,9,14,7,14,0,0,0,0,4);
	InitH(&player->leftHitBox,-7,-15,-9,-15,-9,14,-7,14,0,0,0,0,4);
	InitT(&player->transform,-30000,-400,10,10);
	InitB(&player->body,1,0,0,0,10,0.2,0.5);
	InitT(&player->sprite.srce,0,0,32,32);
	InitT(&player->sprite.dest,0,0,32,32);
	player->sprite.texture = LoadTexture(camera,"./src/resources/playerSprite.png");
	player->sprite.frameTime = 0;
	player->maxJumpTime = 5;
	player->minJumpTime = 5;
	player->jumpTime = 0;
	InitV(&player->keyForce,0,0);
	InitV(&player->gravity,0,98.1);
	InitV(&player->jump,0,-500);
	InitV(&player->fly,0,-120);
	player->power = 0;
	player->walkSound = Mix_LoadWAV( "./src/resources/WalkSound.wav" );
	player->jumpSound = Mix_LoadWAV( "./src/resources/JumpSound.wav" );
	player->powerupSound = Mix_LoadWAV( "./src/resources/PowerupSound.wav" );
	player->wind = Mix_LoadWAV( "./src/resources/Wind.wav" );

}

void UpdatePlayer(S_scene_lvl1* sc,E_input* input,E_camera* camera){

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
	if(!player->hitTop && input->key[input->up]){ //z
		jump = true;
	}
	if(!player->hitBottom && input->key[input->down]){ //s
		player->keyForce.y += 1;
	}
	if(!player->hitLeft && input->key[input->left]){ //q
		player->keyForce.x -= 1;
	}
	if(!player->hitRight && input->key[input->right]){ //d
		player->keyForce.x += 1;
	}
	if(player->hitStep && player->hitBottom && !player->hitRight && !player->hitLeft){
		player->keyForce.y -= 2*fabsf(player->keyForce.x);
	}

	//--------calcul du deplacement---------

	MulV(&player->keyForce,35);

	if(!player->hitBottom){ 												//le joueur ne touche pas en bas donc il est en l'air
		AddForceB(&player->body,&player->gravity);							//on applique donc la gravité
		if(jump && player->jumpTime>0){ 									//si il reste de temps  de saut et q l'on saute
			player->jumpTime--;													//on reduit le temps de saut
			AddForceB(&player->body,&player->fly);							//appliquer une force de vol

		}
	}else{																	//le joueur touche en bas donc il est au sol
		if(player->jumpTime<player->minJumpTime){
			player->jumpTime = player->minJumpTime;							//on reinit le temps de saut
		}
		if(jump){															//si l'on saute
			AddForceB(&player->body,&player->jump);							//appliquer une force de saut initale
			Mix_PlayChannel( -1, player->jumpSound, 0 );					//lancer le son du saut
		}
	}
	AddForceB(&player->body,&player->keyForce);
	ApplyForceB(&player->body);
	AddFrictionB(&player->body);

	//une fois la veloc calculée on teste si apres deplacement on touche qqch
	//il faut donc obtenir une copie de la position future et tester si on peut s'y deplacer

	//----test collision map------
	P_vector velTest = VEqu(&player->body.velocity);
	P_vector posTest = VAdd(&player->transform.position,&velTest);


	bool collide = false;
	collide = TestCollisionMap(player,&posTest,&player->hitBox,&sc->tileMap,-2,+2,-2,+2);

	if(!collide){
		//printf("no col %f; %f \n",player->body.velocity.x,player->body.velocity.y);
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
			MulV(&velTest,0.9);
			posTest = VAdd(&player->transform.position,&velTest);
			if(DistanceV(&posTest,&player->transform.position)<50){
				AddV(&player->transform.position,&velTest);
			}

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
			//printf("col %f; %f \n",player->body.velocity.x,player->body.velocity.y);
		}
	}

	//----animation de perso-----------
	int currentTime = SDL_GetTicks();
	if(currentTime%(PLAYER_FRAME*4) == 0){
		Mix_PlayChannel( -1, player->wind, 0 );
	}
	if(currentTime - player->sprite.frameTime > PLAYER_FRAME){

		if(MagnitudeV(&player->body.velocity)>0.1){				//le perso bouge donc anim walk
			if(player->body.velocity.x>0){						//le perso va a droite
				player->sprite.srce.position.y = 1;
			}else{
				player->sprite.srce.position.y = 3;
			}

		}else{
			if(player->body.velocity.x>0){						//le perso allais droite
				player->sprite.srce.position.y = 0;
			}
			if(player->body.velocity.x<0){						//le perso allais gauche
				player->sprite.srce.position.y = 2;
			}
		}
		player->sprite.srce.position.x++;
		if(player->sprite.srce.position.x > 11){
			player->sprite.srce.position.x = 0;

		}
		if(MagnitudeV(&player->body.velocity)>0.1  && (player->sprite.srce.position.x == 0 || player->sprite.srce.position.x == 6) && player->hitBottom){
			Mix_PlayChannel( -1, player->walkSound, 0 );
		}
		player->sprite.frameTime = currentTime;
	}
	SetRectSprite(&player->sprite,&player->transform);

	//----contol camera

	camera->transform.scale.x = input->mouseywheel;
	camera->transform.scale.y = input->mouseywheel;

	if(camera->transform.scale.x>0.75){
		camera->transform.scale.x=0.75;
		input->mouseywheel=0.75;
	}
	if(camera->transform.scale.x<0.25){
		camera->transform.scale.x=0.25;
		input->mouseywheel=0.25;
	}
	if(camera->transform.scale.y>0.75){
		camera->transform.scale.y=0.75;
		input->mouseywheel=0.75;
	}
	if(camera->transform.scale.y<0.25){
		camera->transform.scale.y=0.25;
		input->mouseywheel=0.25;
	}

	//printf("%f\n",camera->transform.scale.x);
	if(DistanceV(&camera->transform.position,&player->transform.position)>10){
		LerpV(&camera->transform.position,&player->transform.position,DistanceV(&player->transform.position,&camera->transform.position)/1000);
	}
	//printf("%f , %f \n",player->sprite.pos.x,player->sprite.pos.y);
	//printf("pos %f; %f \n",player->transform.position.x,player->transform.position.y);
	//printf("vel %f; %f \n",player->body.velocity.x,player->body.velocity.y);
	//printf("%f; %f \n",camera->transform.position.x,camera->transform.position.y);

	//------control powerjump / interaction avec tileMap

	int px = GetMapPos(&player->transform.position,&sc->tileMap).x;
	int py = GetMapPos(&player->transform.position,&sc->tileMap).y;
	int k = px+py*sc->tileMap.sizeMapX;

	//printf("[%d,%d]=%d \n",px,py,sc->tileMap.tileRef[3][k]);
	//printf("%d \n",player->maxJumpTime);
	if(sc->tileMap.tileRef[2][k] > 168 && sc->tileMap.tileRef[2][k] < 173){
		sc->tileMap.tileRef[2][k] = 0;
		player->maxJumpTime += 14;
		player->power ++;
		Mix_PlayChannel( -1, player->powerupSound, 0 );
	}
	if(sc->tileMap.tileRef[2][k] > 25 && sc->tileMap.tileRef[2][k] < 29){
		player->jumpTime = player->maxJumpTime;								//on met le temps de saut au max
	}
	if(sc->tileMap.tileRef[2][k] == 196){
		printf("%d\n",sc->textTimer.timer.current-sc->textTimer.timer.start);								//on fini le lvl
		EndTextTimer(sc,input);
		input->scene = 0;
	}
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
				P_hitBox hbmap = HMatchPS(&tileMap->hitBox[tileMap->tileRef[2][k]],&mapPos,&tileMap->transform.scale);
				collision = CollisionAB(&hbmap,&hb);
				//printf("\t collision : %d \n",collision);
				if(collision)return true;
			}
		}
	}
	return false;
}

void RenderPlayer(S_scene_lvl1* sc,E_camera* camera){

	G_player* player = &sc->player;
	RenderGameObject(camera,&player->sprite);

}

