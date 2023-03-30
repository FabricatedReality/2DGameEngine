#include <iostream>
#include <new>

#include "init.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const char* GAME_NAME = "Game Engine";

int main(int argc, char** argv)
{
	App app = {nullptr, nullptr, nullptr};

	if(!initApp(app)) {
		std::cout << "Failed to initialize program" << std::endl;
		closeProgram();
		return 0;
	}
	if(!loadMedia()) {
		std::cout << "Failed to load image" << std::endl;
		closeProgram();
		return 0;
	}

	// Put the image on
	SDL_BlitSurface(app.image, NULL, app.surface, NULL);
	// Update the window
	SDL_UpdateWindowSurface(app.surface);

	SDL_Event e;
	bool running = true;
	while(running) {
		while(SDL_PollEvent(&e))
			if(e.type == SDL_QUIT)
				running = false;
	}

	closeProgram();
	return 0;
}