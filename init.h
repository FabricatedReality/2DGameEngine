struct SDLProgram{
	SDL_Window *window;
	SDL_Surface* surface;
	SDL_Surface* image;

	SDLProgram() : window(nullptr), surface(nullptr), image(nullptr) {}
}App;

// Initialize SDL and create a window
bool initApp(App &app);

// Load media onto the window
bool loadMedia();

// Free memories and shut down the program
void closeProgram();