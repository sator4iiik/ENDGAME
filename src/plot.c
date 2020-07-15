#include "../inc/plot.h"
#include "../resource/SDL2/SDL_image.h"

static void tick(void);
static void touch();
void jopa1(void);
Entity *e;
int k = 0;
SDL_Event event;

void initPlot(char *line) {
	Entity *e;
	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;
	sscanf(line, "%*s %f %f", &e->x, &e->y);
	e->health = 1;	
	e->texture = loadTexture("resource/texture/go.png");
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->flags = EF_WEIGHTLESS;
	e->tick = tick;
	e->touch = touch;
	
	stage.energyTotal++;
}

static void tick(void) {
	self->value += 0;
	self->y += sin(self->value);
}

static void touch(Entity *other) {
	if (other == player && stage.energyFound == 13) {
        jopa1();
	}
}

void jopa1(void) {
	SDL_Texture *texture = NULL;
	texture = IMG_LoadTexture(app.renderer, "resource/texture/load.png");
	SDL_RenderCopy(app.renderer, texture, NULL, NULL);
	SDL_RenderPresent(app.renderer);
	while (1) {
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {		
			exit(0);
			break;
		}
	}
}

