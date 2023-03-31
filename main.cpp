// System libraries
#include <iostream>
#include <new>
// Libraries
#include <SDL.h>
// Project files
#include "init.h"

int main(int argc, char* argv[])
{
	App app;

	if(!initApp(app)) {
		std::cout << "Failed to initialize program" << std::endl;
		closeProgram(app);
		return 0;
	}
	if(!loadMedia(app, "assets/", "test.bmp")) {
		std::cout << "Failed to load image" << std::endl;
		closeProgram(app);
		return 0;
	}

	SDL_Event e;
	bool running = true;
	while(running) {
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT)
				running = false;
		}
		// Put the image on
		SDL_BlitSurface(app.image, NULL, app.surface, NULL);
		// Update the window
		SDL_UpdateWindowSurface(app.window);
	}

	closeProgram(app);
	return 0;
}