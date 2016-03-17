#include "physics.h"

void InitV(P_vector* v,float x, float y){
	v->x = x;
	v->y = y;
}

void EquV(P_vector* v1, P_vector* v2) {
	v1->x = v2->x;
	v1->y = v2->y;
}

void AddV(P_vector* v1, P_vector* v2) {
	v1->x += v2->x;
	v1->y += v2->y;
}

void SubV(P_vector* v1, P_vector* v2) {
	v1->x -= v2->x;
	v1->y -= v2->y;
}

void MulV(P_vector* v,float f){
	v->x *= f;
	v->y *= f;
}

void DivV(P_vector* v,float f){
	if(f!=0){
		v->x /= f;
		v->y /= f;
	}
}

float MagnitudeV(P_vector* v){
	return sqrt(v->x*v->x + v->y*v->y);
}

void NormalizeV(P_vector* v){
	float m = MagnitudeV(v);
	DivV(v,m);
}

void ToCenterSpaceV(float* x,float* y){
	*x += SCREEN_WIDTH / 2;
	*y += SCREEN_HEIGHT / 2;
}

