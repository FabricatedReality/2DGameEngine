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

// Load media onto the window
bool loadMedia(App &app, std::string directory, std::string imageName);

// Free memories and shut down the program
void closeProgram(App &app);