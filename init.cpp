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

	app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
	if(app.renderer == NULL) {
		std::cout << "Renderer could not be created: " << SDL_GetError() << std::endl;
		return false;
	}
	SDL_SetRenderDrawColor(app.renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int flags = IMG_INIT_PNG;
	if((IMG_Init(flags)&flags) != flags) {
		std::cout << "SDL_image could not be initialized: " << IMG_GetError() << std::endl;
		return false;
	}

	return true;
}

// Loads in image as texture
SDL_Texture* loadTexture(std::string path)
{
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL) {
		std::cout << "Failed to load image " << path.c_str() << std::endl << IMG_GetError() << std::endl;
		return NULL;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(app.renderer, loadedSurface);
	if(texture == NULL)
		std::cout << "Failed to create texture " << path.c_str() << std::endl << SDL_GetError() << std::endl;
	SDL_FreeSurface(loadedSurface);
	return texture;
}

// Load media onto the window
bool loadMedia(SDL_Texture *(&keyPressSurfaces)[KEY_PRESS_TOTAL])
{
	keyPressSurfaces[KEY_PRESS_DEFAULT] = loadTexture("assets/test.jpg");
	if(keyPressSurfaces[KEY_PRESS_DEFAULT] == NULL) {
		std::cout << "Failed to load default image" << std::endl;
		return false;
	}
	keyPressSurfaces[KEY_PRESS_UP] = loadTexture("assets/up.png");
	if(keyPressSurfaces[KEY_PRESS_UP] == NULL) {
		std::cout << "Failed to load up image" << std::endl;
		return false;
	}
	keyPressSurfaces[KEY_PRESS_DOWN] = loadTexture("assets/down.bmp");
	if(keyPressSurfaces[KEY_PRESS_DOWN] == NULL) {
		std::cout << "Failed to load down image" << std::endl;
		return false;
	}
	keyPressSurfaces[KEY_PRESS_LEFT] = loadTexture("assets/left.bmp");
	if(keyPressSurfaces[KEY_PRESS_LEFT] == NULL) {
		std::cout << "Failed to load left image" << std::endl;
		return false;
	}
	keyPressSurfaces[KEY_PRESS_RIGHT] = loadTexture("assets/right.png");
	if(keyPressSurfaces[KEY_PRESS_RIGHT] == NULL) {
		std::cout << "Failed to load right image" << std::endl;
		return false;
	}
	return true;
}

// Free memories and shut down the program
void closeProgram()
{
	SDL_DestroyTexture(app.texture);
	app.texture = nullptr;

	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	app.window = nullptr;
	app.renderer = nullptr;

	IMG_Quit();
	SDL_Quit();
}