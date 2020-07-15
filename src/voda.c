#include "../inc/voda.h"
#include "../resource/SDL2/SDL_image.h"

static void tick(void);
void jopa1(void);
Entity *e;



void initVoda(char *line) {
	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;
	sscanf(line, "%*s %f %f %f %f", &e->sx, &e->sy, &e->ex, &e->ey);
	e->health = 1;
	e->x = e->sx;
	e->y = e->sy;
	e->tick = tick;
	e->texture = loadTexture("resource/texture/IMG_0552.jpeg");
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->flags = EF_WEIGHTLESS;//+EF_PUSH; EF_SOLID
}

static void tick(void) {
	if (fabsf(self->x - self->sx) < VODA_SPEED && fabsf(self->y - self->sy) < VODA_SPEED) {
		calcSlope(self->ex, self->ey, self->x, self->y, &self->dx, &self->dy);
		self->dx *= VODA_SPEED;
		self->dy *= VODA_SPEED;

	}
	if (fabsf(self->x - self->ex) < VODA_SPEED && fabsf(self->y - self->ey) < VODA_SPEED) {
		calcSlope(self->sx, self->sy, self->x, self->y, &self->dx, &self->dy);
		self->dx *= VODA_SPEED;
		self->dy *= VODA_SPEED;
	}
}




