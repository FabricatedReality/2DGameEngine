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

// Loads in image as texture
SDL_Texture* loadTexture(std::string path);

// Load media onto the window
bool loadMedia(SDL_Texture *(&keyPressSurfaces)[KEY_PRESS_TOTAL]);

// Free memories and shut down the program
void closeProgram();
#endif