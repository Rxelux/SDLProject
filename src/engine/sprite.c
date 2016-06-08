#include "engineFonct.h"

void SetRectSprite(S_sprite* s,P_transform* transform){

	s->srcerect.x = s->srce.position.x * s->srce.scale.x;
	s->srcerect.y = s->srce.position.y * s->srce.scale.y;
	s->srcerect.w = s->srce.scale.x;
	s->srcerect.h = s->srce.scale.y;

	s->dest.position.x = transform->position.x - (s->dest.scale.x/2) * transform->scale.x;
	s->dest.position.y = transform->position.y - (s->dest.scale.y/2) * transform->scale.y;
	s->destrect.w = s->dest.scale.x * transform->scale.x;
	s->destrect.h = s->dest.scale.y * transform->scale.y;
	//printf("%d ; %d",s->rect.w,s->rect.h);
}
void SetRectText(S_sprite* s,P_transform* transform,SDL_Texture* texture){

	s->srcerect.x = s->srce.position.x * s->srce.scale.x;
	s->srcerect.y = s->srce.position.y * s->srce.scale.y;
	SDL_QueryTexture( texture, NULL, NULL, &s->srcerect.w, &s->srcerect.h );

	s->dest.position.x = transform->position.x - ((s->dest.scale.x * s->srcerect.w)/2) * transform->scale.x;
	s->dest.position.y = transform->position.y - ((s->dest.scale.y * s->srcerect.h)/2) * transform->scale.y;
	s->destrect.w = s->srcerect.w * s->dest.scale.x * transform->scale.x ;
	s->destrect.h = s->srcerect.h * s->dest.scale.y * transform->scale.y ;
	//printf("%d ; %d",s->rect.w,s->rect.h);
}
