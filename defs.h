#ifndef DEFS_H
#define DEFS_H

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