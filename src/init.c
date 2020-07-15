#include "../inc/init.h"
#include "../resource/SDL2/SDL_mixer.h"

Mix_Music *backgroundSound;


void initSDL(void) {
	int rendererFlags, windowFlags;
	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Couldn't initialize SDL Mixer\n");
		exit(1);
	}
    Mix_AllocateChannels(MAX_SND_CHANNELS);
	app.window = SDL_CreateWindow("if", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	SDL_ShowCursor(0);
}

void initGame(void) {
	initFonts();
	initSounds();
	loadMusic("resource/sounds/5.mp3");
	playMusic(1);
}

void cleanup(void) {
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	Mix_CloseAudio();
	SDL_Quit();
}
