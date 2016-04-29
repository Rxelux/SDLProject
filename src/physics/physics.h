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
P_vector VInit(float x, float y);
void EquV(P_vector* v1, P_vector* v2);
P_vector VEqu(P_vector* v1);
void AddV(P_vector* v1, P_vector* v2);
P_vector VAdd(P_vector* v1, P_vector* v2);
void SubV(P_vector* v1, P_vector* v2);
P_vector VSub(P_vector* v1, P_vector* v2);
void MulV(P_vector* v,float f);
P_vector VMul(P_vector* v,float f);
void DivV(P_vector* v,float f);
P_vector VDiv(P_vector* v,float f);

float MagnitudeV(P_vector* v);
void NormalizeV(P_vector* v);
P_vector VNormalize(P_vector* v);
float DistanceV(P_vector* v1,P_vector* v2);

void ToCenterSpaceV(P_vector* v);
P_vector VToCenterSpace(P_vector* v);
void ToWindowSpaceV(P_vector* v);
P_vector VToWindowSpace(P_vector* v);

void LerpV(P_vector* src,P_vector* dest,float time);
P_vector VLerp(P_vector* src,P_vector* dest,float time);

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

//----HITBOX-----------------------------------------------------

typedef struct{
	P_vector tab[6];
	int nbp;
}P_hitBox;

void InitH(P_hitBox* hitBox,float a,float b,float c,float d,float e,float f,float g,float h,float i,float j,float k,float l,int nbp);
P_hitBox HInit(float a,float b,float c,float d,float e,float f,float g,float h,float i,float j,float k,float l,int nbp);
void EquH(P_hitBox* hb1, P_hitBox* hb2);
P_hitBox HEqu(P_hitBox* hb);
P_hitBox HMatchT(P_hitBox* hbIn,P_transform* transform);
P_hitBox HMatchPS(P_hitBox* hbIn,P_vector* position,P_vector* scale);
void MatchHT(P_hitBox* hb,P_transform* transform);

int intersectsegment(P_vector A,P_vector B,P_vector I,P_vector P);
bool Collision(P_hitBox* ply,P_vector* P);
bool CollisionAB(P_hitBox* ply1, P_hitBox* ply2);
bool CollisionDroiteSeg(P_vector* A,P_vector* B,P_vector* O,P_vector* P);
bool CollisionSegSeg(P_vector* A,P_vector* B,P_vector* O,P_vector* P);

#endif /* PHYSICS_PHYSICS_H_ */

