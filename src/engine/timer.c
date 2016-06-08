#include "engineFonct.h"

int HasStartedT(E_timer* timer){
	return timer->current-timer->start > 0 ? 1 : 0;
}
int HasEndedT(E_timer* timer){
	return timer->current-timer->end > 0 ? 1 : 0;
}
int IsRunningT(E_timer* timer){
	return HasStartedT(timer) && !HasEndedT(timer);
}
float GetProgressT(E_timer* timer){
	if(timer->end-timer->start!=0){
		return (timer->current-timer->start)/((float)timer->end-timer->start);
	}
	return 1;

}
void StartT(E_timer* timer,int duration){
	timer->current = timer->start = SDL_GetTicks();
	timer->end = timer->start+duration;
	timer->current++;
}
void UpdateT(E_timer* timer){
	if(HasStartedT(timer)){
		timer->current = SDL_GetTicks();
	}
	if(HasEndedT(timer)){
		timer->current = timer->start = timer->end = 0;
	}
}
