/*
 * physics.h
 *
 *  Created on: 10 mars 2016
 *      Author: robinpelletier
 */

#ifndef PHYSICS_PHYSICS_H_
#define PHYSICS_PHYSICS_H_

#include "../header.h"

//----VECTOR------------------------------------------------

typedef struct{
	float x;
	float y;
}P_vector;

void InitV(P_vector* v,float x, float y);
void EquV(P_vector* v1, P_vector* v2);
void AddV(P_vector* v1, P_vector* v2);
void SubV(P_vector* v1, P_vector* v2);
void MulV(P_vector* v,float f);
void DivV(P_vector* v,float f);
float MagnitudeV(P_vector* v);
void NormalizeV(P_vector* v);
void ToCenterSpaceV(float* x,float* y);

//----TRANSFORM---------------------------------------------

typedef struct{
	P_vector position;
	P_vector scale;
}P_transform;

void InitT(P_transform* t,float px, float py, float sx, float sy);
void EquT(P_transform* t1, P_transform* t2);

//----BODY--------------------------------------------------

typedef struct{
	P_vector velocity;
	P_vector acceleration;
	float mass;
	float coefFriction;
	float coefBounciness;
}P_body;
//TODO limiter la velocité min max ,limiter l'acceleration min max
void InitB(P_body* body, float vx, float vy,float ax, float ay,float m,float c,float b);
void AddForceB(P_body* b,P_vector* f);
void ApplyForceB(P_body* b);
void AddFrictionB(P_body* b);

#endif /* PHYSICS_PHYSICS_H_ */

