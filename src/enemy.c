#include "../inc/enemy.h"

static void tick(void);
Entity *e;
Stage stage;
Entity *player;
Entity *player2;

static void touch();

void initEnemy(char *line) {
	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;
	sscanf(line, "%*s %f %f %f %f", &e->sx, &e->sy, &e->ex, &e->ey);
	e->health = 1;
	e->x = e->sx;
	e->y = e->sy;
	e->tick = tick;
	e->touch = touch;
	e->texture = loadTexture("resource/texture/enemy.png");
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->flags = EF_WEIGHTLESS;//+EF_PUSH; EF_SOLID
}

static void tick(void) {
	if (fabsf(self->x - self->sx) < ENEMY_SPEED && fabsf(self->y - self->sy) < ENEMY_SPEED) {
		calcSlope(self->ex, self->ey, self->x, self->y, &self->dx, &self->dy);
		self->dx *= ENEMY_SPEED;
		self->dy *= ENEMY_SPEED;

	}

	if (fabsf(self->x - self->ex) < ENEMY_SPEED && fabsf(self->y - self->ey) < ENEMY_SPEED) {
		calcSlope(self->sx, self->sy, self->x, self->y, &self->dx, &self->dy);
		self->dx *= ENEMY_SPEED;
		self->dy *= ENEMY_SPEED;
	}
}

static void touch(Entity *other) {
	if (self->health > 0 && other == player ) {
		self->health = 0;
		stage.energyFound--;
		playSound(SND_ENERGY, CH_ENERGY);
		
	}
	else if (self->health > 0 && other == player2 ) {
		self->health = 0;
		player2->health--;

	}
}
