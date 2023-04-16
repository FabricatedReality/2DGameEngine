#include "init.h"

// Initialize SDL and create a window
bool initApp()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL initialize failure: " << SDL_GetError() << std::endl;
		return false;
	}
	
	app.window = SDL_CreateWindow(constants::GAME_TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
								  constants::SCREEN_WIDTH, constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(app.window == NULL) {
		std::cout << "Window could not be created: " << SDL_GetError() << std::endl;
		return false;
	}

	app.surface = SDL_GetWindowSurface(app.window);
	return true;
}

// Loads a surface
SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* surface = NULL;
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if(loadedSurface == NULL) {
		std::cout << "Failed to load image: " << SDL_GetError() << std::endl;
	} else {
		surface = SDL_ConvertSurface(loadedSurface, app.surface->format, 0);
		if(surface == NULL) {
			std::cout << "Unable to optimize image " << path << std::endl;
			std::cout << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(loadedSurface);
	}
	return surface;
}

//change dest to a stretched version of SDL_Surface srcSur
void stretchedSurface(SDL_Surface* srcSur, SDL_Surface* dest, int width, int height)
{
	SDL_Rect sizeRect;
	sizeRect.x = 0;
	sizeRect.y = 0;
	sizeRect.w = width;
	sizeRect.h = height;

	SDL_BlitScaled(srcSur, NULL, dest, &sizeRect);
}

// Load media onto the window
bool loadMedia(SDL_Surface *(&keyPressSurfaces)[KEY_PRESS_TOTAL])
{
	keyPressSurfaces[KEY_PRESS_DEFAULT] = loadSurface("assets/test.bmp");
	if(keyPressSurfaces[KEY_PRESS_DEFAULT] == NULL) {
		std::cout << "Failed to load default image" << std::endl;
		return false;
	}
	keyPressSurfaces[KEY_PRESS_UP] = loadSurface("assets/up.bmp");
	if(keyPressSurfaces[KEY_PRESS_UP] == NULL) {
		std::cout << "Failed to load up image" << std::endl;
		return false;
	}
	keyPressSurfaces[KEY_PRESS_DOWN] = loadSurface("assets/down.bmp");
	if(keyPressSurfaces[KEY_PRESS_DOWN] == NULL) {
		std::cout << "Failed to load down image" << std::endl;
		return false;
	}
	keyPressSurfaces[KEY_PRESS_LEFT] = loadSurface("assets/left.bmp");
	if(keyPressSurfaces[KEY_PRESS_LEFT] == NULL) {
		std::cout << "Failed to load left image" << std::endl;
		return false;
	}
	keyPressSurfaces[KEY_PRESS_RIGHT] = loadSurface("assets/right.bmp");
	if(keyPressSurfaces[KEY_PRESS_RIGHT] == NULL) {
		std::cout << "Failed to load right image" << std::endl;
		return false;
	}
	return true;
}

// Free memories and shut down the program
void closeProgram()
{
	SDL_FreeSurface(app.surface);
	SDL_DestroyWindow(app.window);
	SDL_Quit();
}