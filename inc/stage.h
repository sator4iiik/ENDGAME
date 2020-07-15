#include "common.h"

extern void doCamera(void);
extern void doEntities(void);
extern void doPlayer(void);
extern void drawEntities(void);
extern void drawMap(void);
extern void initEntities(void);
extern void initMap(void);
extern void initPlayer(void);
extern void drawText(int x, int y, int r, int g, int b, int align, char *format, ...);
extern void blit(SDL_Texture *texture, int x, int y);
extern void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
extern void calcSlope(int x1, int y1, int x2, int y2, float *dx, float *dy);
extern int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
extern SDL_Texture *loadTexture(char *filename);
extern void initPlayer2(void);
extern void doPlayer2(void);
static void initStarfield(void);
static void drawStarfield(void);
static void doStarfield(void);

extern App app;
extern Stage stage;
