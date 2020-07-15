#include "../inc/energy.h"

static void tick(void);
static void touch();

void initEnergy(char *line) {
	Entity *e;
	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;
	sscanf(line, "%*s %f %f", &e->x, &e->y);
	e->health = 1;	
	e->texture = loadTexture("resource/texture/energy.png");
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->flags = EF_NONE + EF_WEIGHTLESS;//EF_NONE + EF_WEIGHTLESS;
	e->tick = tick;
	e->touch = touch;
	
	stage.energyTotal++;
}

static void tick(void) {
	self->value += 0.1;
	self->y += sin(self->value);
}

static void touch() {
	if (self->health > 0)
	{
		self->health = 0;
		stage.energyFound++;
		playSound(SND_ENERGY_DONE, CH_ENERGY);
	}
}

