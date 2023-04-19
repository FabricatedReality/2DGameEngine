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
	SDL_Texture* keyPressSurfaces[KEY_PRESS_TOTAL];

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
	app.texture = keyPressSurfaces[KEY_PRESS_DEFAULT];

	while(running) {
		while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT) {
				running = false;
			} else if(e.type == SDL_KEYDOWN) {
				if(e.key.keysym.sym == SDLK_UP)
					app.texture = keyPressSurfaces[KEY_PRESS_UP];
				else if(e.key.keysym.sym == SDLK_DOWN)
					app.texture = keyPressSurfaces[KEY_PRESS_DOWN];
				else if(e.key.keysym.sym == SDLK_LEFT)
					app.texture = keyPressSurfaces[KEY_PRESS_LEFT];
				else if(e.key.keysym.sym == SDLK_RIGHT)
					app.texture = keyPressSurfaces[KEY_PRESS_RIGHT];
				else
					app.texture = keyPressSurfaces[KEY_PRESS_DEFAULT];
			}
		}
		// Clear screen
		SDL_RenderClear(app.renderer);
		// Render texture to screen
		SDL_RenderCopy(app.renderer, app.texture, NULL, NULL);
		// Update screen
		SDL_RenderPresent(app.renderer);
	}

	closeProgram();
	for(int i = 0; i < KEY_PRESS_TOTAL; i++)
		SDL_DestroyTexture(keyPressSurfaces[i]);
	return 0;
}