#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define STRNCPY(dest, src, n) strncpy(dest, src, n); dest[n - 1] = '\0'

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720

#define MAX_STARS   200

#define MAX_TILES    7

#define TILE_SIZE    64

#define MAP_WIDTH    80
#define MAP_HEIGHT   20

#define MAP_RENDER_WIDTH    20
#define MAP_RENDER_HEIGHT   12

#define PLAYER_MOVE_SPEED 5

#define MAX_NAME_LENGTH        32
#define MAX_LINE_LENGTH        1024
#define MAX_FILENAME_LENGTH    1024

#define MAX_KEYBOARD_KEYS 250

#define MAX_SND_CHANNELS 16

#define EF_NONE       0
#define EF_WEIGHTLESS (2 << 0)
#define EF_SOLID      (2 << 1)
#define EF_PUSH       (2 << 2)

#define GLYPH_WIDTH  18
#define GLYPH_HEIGHT 29


enum
{
	TEXT_LEFT,
	TEXT_CENTER,
	TEXT_RIGHT
};

enum
{
	SND_JUMP,
	SND_ENERGY,
	SND_ENERGY_DONE,
	SND_MAX
};

enum
{
	CH_PLAYER,
	CH_ENERGY
};
