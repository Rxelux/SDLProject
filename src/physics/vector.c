#include "physics.h"

void InitV(P_vector* v,float x, float y){
	v->x = x;
	v->y = y;
}
P_vector VInit(float x, float y){
	P_vector u;
	InitV(&u,x,y);
	return u;
}

void EquV(P_vector* v1, P_vector* v2) {
	InitV(v1,v2->x,v2->y);
}

P_vector VEqu(P_vector* v){
	return VInit(v->x,v->y);
}

void AddV(P_vector* v1, P_vector* v2) {
	InitV(v1,v1->x + v2->x,v1->y + v2->y);
}

P_vector VAdd(P_vector* v1, P_vector* v2){
	return VInit(v1->x + v2->x,v1->y + v2->y);
}

void SubV(P_vector* v1, P_vector* v2) {
	InitV(v1,v1->x - v2->x,v1->y - v2->y);
}

P_vector VSub(P_vector* v1, P_vector* v2){
	return VInit(v1->x - v2->x,v1->y - v2->y);
}

void MulV(P_vector* v,float f){
	InitV(v,v->x * f,v->y * f);
}

P_vector VMul(P_vector* v,float f){
	return VInit(v->x * f,v->y * f);
}

void DivV(P_vector* v,float f){
	if(f!=0){
		InitV(v,v->x / f,v->y / f);
	}
}

P_vector VDiv(P_vector* v,float f){
	if(f!=0){
		return VInit(v->x / f,v->y / f);
	}
	return *v;
}

float MagnitudeV(P_vector* v){
	return sqrt(v->x*v->x + v->y*v->y);
}

void NormalizeV(P_vector* v){
	float m = MagnitudeV(v);
	DivV(v,m);
}

P_vector VNormalize(P_vector* v){
	float m = MagnitudeV(v);
	return VDiv(v,m);
}

float DistanceV(P_vector* v1,P_vector* v2){
    return sqrt(pow(v2->x-v1->x,2)+pow(v2->y-v1->y,2));
}

void ToCenterSpaceV(P_vector* v){
	InitV(v,v->x + SCREEN_WIDTH / 2,v->y + SCREEN_HEIGHT / 2);
}

P_vector VToCenterSpace(P_vector* v){
	return VInit(v->x + SCREEN_WIDTH / 2,v->y + SCREEN_HEIGHT / 2);
}

void ToWindowSpaceV(P_vector* v){
	InitV(v,v->x - SCREEN_WIDTH / 2,v->y - SCREEN_HEIGHT / 2);
}

P_vector VToWindowSpace(P_vector* v){
	return VInit(v->x - SCREEN_WIDTH / 2,v->y - SCREEN_HEIGHT / 2);
}

void LerpV(P_vector* src,P_vector* dest,float time){
	if(time>1)time=1;
	if(time<0)time=0;
	InitV(src,src->x*(1-time) + dest->x*time,src->y*(1-time) + dest->y*time);
}

void LerpF(float* src,float dest,float time){
	if(time>1)time=1;
	if(time<0)time=0;
	*src = *src*(1-time) + dest*time;
}

P_vector VLerp(P_vector* src,P_vector* dest,float time){
	if(time>1)time=1;
	if(time<0)time=0;
	return VInit(src->x*(1-time) + dest->x*time,src->y*(1-time) + dest->y*time);
}

