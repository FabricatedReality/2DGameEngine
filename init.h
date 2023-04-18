#ifndef INIT_H
#define INIT_H
// System libraries
#include <iostream>
#include <string>
// Libraries
#include <SDL.h>
#include <SDL_image.h>
// Project files
#include "defs.h"

// Initialize SDL and create a window
bool initApp();

// Loads a surface
SDL_Surface* loadSurface(std::string path);

//change dest to a stretched version of SDL_Surface srcSur
void stretchedSurface(SDL_Surface* srcSur, SDL_Surface* dest, int width, int height);

// Load media onto the window
bool loadMedia(SDL_Surface *(&keyPressSurfaces)[KEY_PRESS_TOTAL]);

// Free memories and shut down the program
void closeProgram();
#endif