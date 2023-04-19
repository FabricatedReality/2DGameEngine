#ifndef DEFS_H
#define DEFS_H

typedef struct SDLProgram{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
}App;

extern App app;

namespace constants{
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	const std::string GAME_TITLE = "Game Engine";
}

enum KeyPressed {
	KEY_PRESS_DEFAULT,
	KEY_PRESS_UP,
	KEY_PRESS_DOWN,
	KEY_PRESS_LEFT,
	KEY_PRESS_RIGHT,
	KEY_PRESS_TOTAL
};
#endif