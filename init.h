#ifndef INIT_H
#define INIT_H
// System libraries
#include <iostream>
#include <string>
// Libraries
#include <SDL.h>
// Project files
#include "defs.h"

typedef struct SDLProgram{
	SDL_Window *window = nullptr;
	SDL_Surface* surface = nullptr;
	SDL_Surface* image = nullptr;
}App;

// Initialize SDL and create a window
bool initApp(App &app);

// Loads a surface
SDL_Surface* loadSurface(std::string path);

// Load media onto the window
bool loadMedia(SDL_Surface *(&keyPressSurfaces)[KEY_PRESS_TOTAL]);

// Free memories and shut down the program
void closeProgram(App &app);
#endif