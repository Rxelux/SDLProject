#include "physics.h"

void InitT(P_transform* t, float px, float py, float sx,float sy){

	InitV(&t->position,px,py);
	InitV(&t->scale,sx,sy);
}

void EquT(P_transform* t1, P_transform* t2){
	t1->position.x = t2->position.x;
	t1->position.y = t2->position.y;
	t1->scale.x = t2->scale.x;
	t1->scale.y = t2->scale.y;
}
