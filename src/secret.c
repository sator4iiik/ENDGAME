#include "../inc/secret.h"

void initSecret(char *line) {
	Entity *e;
	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;
	sscanf(line, "%*s %f %f", &e->x, &e->y);
	e->health = 1;
	e->texture = loadTexture("resource/texture/secret.png");
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->flags = EF_WEIGHTLESS ;
}
