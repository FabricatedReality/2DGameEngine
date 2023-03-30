#include "init.h"

// Initialize SDL and create a window
bool initApp(App &app)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL initialize failure: " << SDL_GetError() << std::endl;
		return false;
	}
	
	app.window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
									  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(app.window == NULL) {
		std::cout << "Window could not be created: " << SDL_GetError() << std::endl;
		return false;
	}

	app.surface = SDL_GetWindowSurface(app.window);
	return true;
}

// Load media onto the window
bool loadMedia(App &app, std::string directory, std::string imageName)
{
	std::string path = directory + imageName;
	app.image = SDL_LoadBMP(path.c_str());
	if(app.image == NULL) {
		std::cout << "Failed to load image: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

// Free memories and shut down the program
void closeProgram(App &app)
{
	SDL_FreeSurface(app.surface);
	SDL_DestroyWindow(app.window);
	SDL_Quit();
}