#include "../inc/stage.h"

static void logic(void);
static void draw(void);
static void drawHud(void);
bool loadMedia();
static Star stars [MAX_STARS];

Entity player2;
SDL_Texture *BG;
SDL_Texture* gTexture = NULL;

int i = 0;
int j = 0;

void initStage(void) {
	app.delegate.logic = logic;
	app.delegate.draw = draw;
	memset(&stage, 0, sizeof(Stage));
	stage.entityTail = &stage.entityHead;
	initEntities();
	initPlayer();
	initPlayer2();
	initMap();
	initStarfield();
}

static void doStarfield(void) {
	int i;
	
	for (i = 0 ; i < MAX_STARS ; i++) {
		stars[i].y -= stars[i].speed;
		if (stars[i].y < 0) {
			stars[i].y = SCREEN_WIDTH + stars[i].y;
		}
	}
}

static void logic(void) {
	doPlayer();
	if(app.keyboard[SDL_SCANCODE_I] && j == 0){
		doPlayer2();
		j++;
	}
	else if(j == 1){
		doPlayer2();
	}
	doEntities();
	doCamera();
	doStarfield();
}

static void draw(void) {
	if(i == 0) {
		loadMedia();
		i++;
	}
	SDL_RenderCopy( app.renderer, gTexture, NULL, NULL );
	drawMap();
	drawEntities();
	drawHud();
	drawStarfield();
}

static void drawHud(void) {
	SDL_Rect r;
	r.x = 0;
	r.y = 0;
	r.w = SCREEN_WIDTH;
	r.h = 65;
	SDL_SetRenderDrawBlendMode(app.renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(app.renderer, 60, 60, 60, 255);
	SDL_RenderFillRect(app.renderer, &r);
	SDL_SetRenderDrawBlendMode(app.renderer, SDL_BLENDMODE_NONE);
	drawText(SCREEN_WIDTH - 5, 5, 255, 255, 255, TEXT_RIGHT, "ENERGY %d/%d", stage.energyFound, stage.energyTotal);
}

bool loadMedia() {
	bool success = true;
	gTexture = loadTexture("resource/texture/tumblr.png");
	if( gTexture == NULL ) {
		printf( "Failed to load texture image!\n" );
		success = false;
	}
	return success;
}

static void initStarfield(void) {
	int i;
	for (i = 0 ; i < MAX_STARS ; i++) {
		stars[i].x = rand() % SCREEN_WIDTH;
		stars[i].y = rand() % SCREEN_HEIGHT;
		stars[i].speed = 1 + rand() % 4;
	}
}

static void drawStarfield(void) {
	int i, c;
	for (i = 0 ; i < MAX_STARS ; i++) {
		c = 32 * stars[i].speed;
		SDL_SetRenderDrawColor(app.renderer, c, c, c, 255);
		SDL_RenderDrawLine(app.renderer, stars[i].x, stars[i].y, stars[i].x + 4, stars[i].y);
	}
}
