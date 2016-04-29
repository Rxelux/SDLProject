#include "physics.h"

void InitB(P_body* body, float vx, float vy,float ax, float ay,float m,float c,float b){
	InitV(&body->velocity,vx,vy);
	InitV(&body->acceleration,ax,ay);
	body->mass = m;
	body->coefFriction = c;
	body->coefBounciness = b;
}

//TODO limiter la velocité min max ,limiter l'acceleration min max

void AddForceB(P_body* b,P_vector* f){

	P_vector force;
	EquV(&force,f);
	DivV(&force,b->mass);
	AddV(&b->acceleration,&force);
}

void ApplyForceB(P_body* b){
	AddV(&b->velocity,&b->acceleration);
	MulV(&b->acceleration,0);

	//printf("%f;%f \n",b->acceleration.x,b->acceleration.y);
}

void AddFrictionB(P_body* b){

	P_vector f;
	EquV(&f,&b->velocity);
	MulV(&f,(float)-1);
	/*if(MagnitudeV(&f)>1){
		NormalizeV(&f);
	}*/
	MulV(&f,b->coefFriction);
	AddV(&b->acceleration,&f);

}
