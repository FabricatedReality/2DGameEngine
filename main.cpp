// System libraries
#include <iostream>
#include <new>
// Libraries
#include <SDL.h>
#include <SDL_image.h>
// Project files
#include "init.h"
#include "defs.h"

App app;

int main(int argc, char* argv[])
{
	SDL_Surface* keyPressSurfaces[KEY_PRESS_TOTAL];

	if(!initApp()) {
		std::cout << "Failed to initialize program" << std::endl;
		closeProgram();
		return 0;
	}
	if(!loadMedia(keyPressSurfaces)) {
		std::cout << "Failed to load image" << std::endl;
		closeProgram();
		return 0;
	}

	SDL_Event e;
	bool running = true;
	app.image = keyPressSurfaces[KEY_PRESS_DEFAULT];

	while(running) {
		while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT) {
				running = false;
			} else if(e.type == SDL_KEYDOWN) {
				if(e.key.keysym.sym == SDLK_UP)
					app.image = keyPressSurfaces[KEY_PRESS_UP];
				else if(e.key.keysym.sym == SDLK_DOWN)
					app.image = keyPressSurfaces[KEY_PRESS_DOWN];
				else if(e.key.keysym.sym == SDLK_LEFT)
					app.image = keyPressSurfaces[KEY_PRESS_LEFT];
				else if(e.key.keysym.sym == SDLK_RIGHT)
					app.image = keyPressSurfaces[KEY_PRESS_RIGHT];
				else
					app.image = keyPressSurfaces[KEY_PRESS_DEFAULT];
			}
		}
		// Put the image on
		stretchedSurface(app.image, app.surface, constants::SCREEN_WIDTH, constants::SCREEN_HEIGHT);
		// Update the window
		SDL_UpdateWindowSurface(app.window);
	}

	closeProgram();
	return 0;
}