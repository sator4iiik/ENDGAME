#include "common.h"

#define VODA_SPEED 0.5

extern void calcSlope(int x1, int y1, int x2, int y2, float *dx, float *dy);
extern SDL_Texture *loadTexture(char *filename);
// extern void playSound(int id, int channel);


App app;
extern Entity *self;
extern Stage stage;
