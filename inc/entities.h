#include "common.h"

extern void blit(SDL_Texture *texture, int x, int y, int center);
extern int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
extern void initBlock(char *line);
extern void initPlatform(char *line);
extern void initEnergy(char *line);
extern int isInsideMap(int x, int y);
extern char *readFile(const char *filename);
extern void initSecret(char *line);
extern void initCloud(char *line);
extern void initFog(char *line);


extern Entity *self;
extern Stage stage;
