#include "../inc/main.h"
#include "../resource/SDL2/SDL_image.h"

static void capFrameRate(long *then, float *remainder);
SDL_Event event;

void jopa(void);

int main(int argc, char *argv[]) {
	long then;
	float remainder;
	int qwer = 1;
	(void) argc;
	(void) argv;
	memset(&app, 0, sizeof(App));
	app.textureTail = &app.textureHead;
	initSDL();
	atexit(cleanup);
	initGame();
	initStage();
	then = SDL_GetTicks();
	remainder = 0;
	stage.energyFound =-7;
	stage.energyTotal = 17;
	while (1) {
		// system("leaks endgame");
		if (qwer == 1) {
			jopa();
			qwer--;
		}
		prepareScene();
		doInput();
		app.delegate.logic();
		app.delegate.draw();
		presentScene();
		capFrameRate(&then, &remainder);
		if(stage.energyFound < 0) {
			stage.energyFound = 0;
		}
	}
	return 0;
}

static void capFrameRate(long *then, float *remainder) {
	long wait, frameTime;
	wait = 15 + *remainder;
	*remainder -= (int)*remainder;
	frameTime = SDL_GetTicks() - *then;
	wait -= frameTime;
	if (wait < 2) {
		wait = 1;
	}	
	SDL_Delay(wait);
	*remainder += 0.3;
	*then = SDL_GetTicks();
}

void jopa(void) {
	SDL_Texture *texture = NULL;
	texture = IMG_LoadTexture(app.renderer, "resource/texture/IMG_0473.png");
	SDL_RenderCopy(app.renderer, texture, NULL, NULL);
	SDL_RenderPresent(app.renderer);
	while (1)
	{
		SDL_RenderCopy(app.renderer, texture, NULL, NULL);
		SDL_RenderPresent(app.renderer);
		if (SDL_PollEvent(&event) && event.type == SDL_KEYDOWN)
			break;
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
			exit(0);
			break;
		}
	}
}
