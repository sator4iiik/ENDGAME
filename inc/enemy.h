#include "common.h"

#define ENEMY_SPEED 2

extern void calcSlope(int x1, int y1, int x2, int y2, float *dx, float *dy);
extern SDL_Texture *loadTexture(char *filename);
extern void playSound(int id, int channel);

extern Entity *self;
extern Stage stage;
