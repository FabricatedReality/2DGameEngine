#include <SDL2/SDL.h>
#include <iostream>

#include "init.h"

// Initialize SDL and create a window
bool initApp(App &app)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL initialize failure: %s\n", SDL_GetError());
		return false;
	}
	
	app.window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
									  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(app.window == NULL) {
		printf("Window could not be created: %s\n", SDL_GetError());
		return false;
	}

	app.surface = SDL_GetWindowSurface(app.window);
	return true;
}

// Load media onto the window
bool loadMedia();

// Free memories and shut down the program
void closeProgram(App &app)
{
	SDL_FreeSurface(app.surface);
	SDL_DestroyWindow(app.window);
	SDL_Quit();
}