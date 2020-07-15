#include "../inc/player.h"

static SDL_Texture *pete[2];
static SDL_Texture *bob[2];

void initPlayer2(void);

void initPlayer(void) {
	player = malloc(sizeof(Entity));
	memset(player, 0, sizeof(Entity));
	stage.entityTail->next = player;
	stage.entityTail = player;
	player->health = 1;
	pete[0] = loadTexture("resource/texture/pete01.png");
	pete[1] = loadTexture("resource/texture/pete02.png");
	player->texture = pete[0];
	player->x = 67;
	SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
}

void doPlayer(void) {
	player->dx = 0;
	if (app.keyboard[SDL_SCANCODE_LEFT]) {
		player->dx = -PLAYER_MOVE_SPEED;
		player->texture = pete[1];
	}

	if (app.keyboard[SDL_SCANCODE_RIGHT]) {
		player->dx = PLAYER_MOVE_SPEED;
		player->texture = pete[0];
	}
	if (app.keyboard[SDL_SCANCODE_I]) {
		player2->x = stage.camera.x = (int)player->x;
		player2->y = stage.camera.y = (int)player->y;
	}
	if (app.keyboard[SDL_SCANCODE_SPACE] && player->isOnGround) {
		player->riding = NULL;
		player->dy = -20;
		playSound(SND_JUMP, CH_PLAYER);
	}

	if (app.keyboard[SDL_SCANCODE_ESCAPE]) {
		player->x = 100;
		player->y = -100;
		app.keyboard[SDL_SCANCODE_ESCAPE] = 0;
	}
}

void initPlayer2(void) {
	player2 = malloc(sizeof(Entity));
	memset(player2, 0, sizeof(Entity));
	stage.entityTail->next = player2;
	stage.entityTail = player2;
	player2->health = 3;
	bob[0] = loadTexture("resource/texture/gr.png");
	bob[1] = loadTexture("resource/texture/gr.png");
	player2->texture = bob[0];
	SDL_QueryTexture(player2->texture, NULL, NULL, &player2->w, &player2->h);
}

void doPlayer2(void) {
	player2->dx = 0;
	if (app.keyboard[SDL_SCANCODE_A]) {
		player2->dx = -PLAYER_MOVE_SPEED;
		player2->texture = bob[1];
	}
	
	if (app.keyboard[SDL_SCANCODE_D]) {
		player2->dx = PLAYER_MOVE_SPEED;
		player2->texture = bob[0];
	}
	
	if (app.keyboard[SDL_SCANCODE_W] && player2->isOnGround) {
		player2->riding = NULL;
		player2->dy = -20;
		
	}
}
