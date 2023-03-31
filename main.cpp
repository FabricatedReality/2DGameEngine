// System libraries
#include <iostream>
#include <new>
// Libraries
#include <SDL.h>
// Project files
#include "init.h"
#include "defs.h"

int main(int argc, char* argv[])
{
	App app;
	SDL_Surface* keyPressSurfaces[KEY_PRESS_TOTAL];

	if(!initApp(app)) {
		std::cout << "Failed to initialize program" << std::endl;
		closeProgram(app);
		return 0;
	}
	if(!loadMedia(keyPressSurfaces)) {
		std::cout << "Failed to load image" << std::endl;
		closeProgram(app);
		return 0;
	}

	SDL_Event e;
	bool running = true;
	app.surface = keyPressSurfaces[KEY_PRESS_DEFAULT];

	while(running) {
		while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT) {
				running = false;
			} else if(e.type == SDL_KEYDOWN) {
				if(e.key.keysym.sym == SDLK_UP)
					app.surface = keyPressSurfaces[KEY_PRESS_UP];
				else if(e.key.keysym.sym == SDLK_DOWN)
					app.surface = keyPressSurfaces[KEY_PRESS_DOWN];
				else if(e.key.keysym.sym == SDLK_LEFT)
					app.surface = keyPressSurfaces[KEY_PRESS_LEFT];
				else if(e.key.keysym.sym == SDLK_RIGHT)
					app.surface = keyPressSurfaces[KEY_PRESS_RIGHT];
				else
					app.surface = keyPressSurfaces[KEY_PRESS_DEFAULT];
			}
			std::cout << app.image << std::endl;
		}
		// Put the image on
		SDL_BlitSurface(app.image, NULL, app.surface, NULL);
		// Update the window
		SDL_UpdateWindowSurface(app.window);
	}

	closeProgram(app);
	return 0;
}