#include "physics.h"

void InitH(P_hitBox* hitBox,float a,float b,float c,float d,float e,float f,float g,float h,float i,float j,float k,float l,int nbp){

	InitV(&hitBox->tab[0],a,b);
	InitV(&hitBox->tab[1],c,d);
	InitV(&hitBox->tab[2],e,f);
	InitV(&hitBox->tab[3],g,h);
	InitV(&hitBox->tab[4],i,j);
	InitV(&hitBox->tab[5],k,l);
	hitBox->nbp = nbp;
}

P_hitBox HInit(float a,float b,float c,float d,float e,float f,float g,float h,float i,float j,float k,float l,int nbp){
	P_hitBox hb;
	InitV(&hb.tab[0],a,b);
	InitV(&hb.tab[1],c,d);
	InitV(&hb.tab[2],e,f);
	InitV(&hb.tab[3],g,h);
	InitV(&hb.tab[4],i,j);
	InitV(&hb.tab[5],k,l);
	hb.nbp = nbp;
	return hb;
}
void EquH(P_hitBox* hb1, P_hitBox* hb2){
	char i;
	hb1->nbp = hb2->nbp;
	for(i=0;i<hb2->nbp;i++){
		EquV(&hb1->tab[i],&hb2->tab[i]);
	}
}
P_hitBox HEqu(P_hitBox* hb2){
	P_hitBox hb1;
	char i;
	hb1.nbp = hb2->nbp;
	for(i=0;i<hb2->nbp;i++){
		hb1.tab[i] = VEqu(&hb2->tab[i]);
	}
	return hb1;
}

P_hitBox HMatchPS(P_hitBox* hbIn,P_vector* position,P_vector* scale){
	P_hitBox hbOut;
	char i;
	hbOut.nbp = hbIn->nbp;
	for(i=0;i<hbIn->nbp;i++){
		hbOut.tab[i] = VInit(hbIn->tab[i].x*scale->x+position->x,
							 hbIn->tab[i].y*scale->y+position->y);
	}
	return hbOut;
}

P_hitBox HMatchT(P_hitBox* hbIn,P_transform* transform){
	P_hitBox hbOut;
	char i;
	hbOut.nbp = hbIn->nbp;
	for(i=0;i<hbIn->nbp;i++){
		hbOut.tab[i] = VInit(hbIn->tab[i].x*transform->scale.x+transform->position.x,
							 hbIn->tab[i].y*transform->scale.y+transform->position.y);
	}
	return hbOut;
}

void MatchHT(P_hitBox* hb,P_transform* transform){
	char i;
	for(i=0;i<hb->nbp;i++){
		InitV(&hb->tab[i],hb->tab[i].x*transform->scale.x+transform->position.x,
							 hb->tab[i].y*transform->scale.y+transform->position.y);
	}
}

int intersectsegment(P_vector A,P_vector B,P_vector I,P_vector P)
{
	P_vector D,E;
	D.x = B.x - A.x;
	D.y = B.y - A.y;
	E.x = P.x - I.x;
	E.y = P.y - I.y;
	double t,u,denom = D.x*E.y - D.y*E.x;
	if (denom==0)
		return -1;   // erreur, cas limite
	t = - (A.x*E.y-I.x*E.y-E.x*A.y+E.x*I.y) / denom;
	if (t<0 || t>=1)
		return 0;
	u = - (-D.x*A.y+D.x*I.y+D.y*A.x-D.y*I.x) / denom;
	if (u<0 || u>=1)
		return 0;
	return 1;
}

bool Collision(P_hitBox* ply,P_vector* P)
{
	int i;
	P_vector I;
	I.x = 10000 + rand()%100;   // 10000 + un nombre aléatoire entre 0 et 99
	I.y = 10000 + rand()%100;
	int nbintersections = 0;

	for(i=0;i<ply->nbp;i++){

		//printf("\n \t \t point ply2 %d : (%f;%f)",i,ply->tab[i].x,ply->tab[i].y);

		P_vector A,B;
		A = VEqu(&ply->tab[i]);

		if (i==ply->nbp-1){  // si c'est le dernier point, on relie au premier
			B = ply->tab[0];
		}
		else {          // sinon on relie au suivant.
			B = ply->tab[i+1];
		}

		int iseg = intersectsegment(A,B,I,*P);
		if (iseg == -1){
			return Collision(ply,P);  // cas limite, on relance la fonction.
		}
		nbintersections+=iseg;
	}
	if (nbintersections%2==1)  // nbintersections est-il impair ?
		return true;
	else
		return false;
}

bool CollisionAB(P_hitBox* ply1, P_hitBox* ply2){

	char i,j;
	P_vector A,B,C,D;
	for(i=0;i<ply1->nbp;i++){

		A = VEqu(&ply1->tab[i]);
		if (i==ply1->nbp-1){  // si c'est le dernier point, on relie au premier
			B = ply1->tab[0];
		}
		else {          // sinon on relie au suivant.
			B = ply1->tab[i+1];
		}

		for(j=0;j<ply2->nbp;j++){

			C = VEqu(&ply2->tab[j]);
			if (j==ply2->nbp-1){  // si c'est le dernier point, on relie au premier
				D = ply2->tab[0];
			}
			else {          // sinon on relie au suivant.
				D = ply2->tab[j+1];
			}
			if(CollisionSegSeg(&A,&B,&C,&D)){
				return true;
			}
		}
	}
	return false;
}

bool CollisionDroiteSeg(P_vector* A,P_vector* B,P_vector* O,P_vector* P)
{
	P_vector AO,AP,AB;
	AB.x = B->x - A->x;
	AB.y = B->y - A->y;
	AP.x = P->x - A->x;
	AP.y = P->y - A->y;
	AO.x = O->x - A->x;
	AO.y = O->y - A->y;
	if ((AB.x*AP.y - AB.y*AP.x)*(AB.x*AO.y - AB.y*AO.x)<0)
		return true;
	else
		return false;
}

bool CollisionSegSeg(P_vector* A,P_vector* B,P_vector* C,P_vector* D)
{
	if (CollisionDroiteSeg(A,B,C,D)==false)
		return false;  // inutile d'aller plus loin si le segment [OP] ne touche pas la droite (AB)
	P_vector AB,CD;
	AB.x = B->x - A->x;
	AB.y = B->y - A->y;
	CD.x = D->x - C->x;
	CD.y = D->y - C->y;
	float k = 0, diviseur = AB.x * CD.y - AB.y * CD.x;

	if(diviseur != 0){
		//m = (AB.x * A->y - AB.x * C->y- AB.y * A->x+ AB.y * C->x ) / diviseur;
		k = (CD.x * A->y - CD.x * C->y - CD.y * A->x + CD.y * C->x ) / diviseur;
	}
	if (k<0 || k>1)
		return false;
	else
		return true;
}
