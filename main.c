#include <stdio.h>
#include <SDL.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const char* GAME_NAME = "Game Engine";

int main(int argc, char** argv)
{
	SDL_Window *window = NULL;
	SDL_Surface* surface = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) >= 0) {
		window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
									SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(window != NULL) {
			surface = SDL_GetWindowSurface(window);

			SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);

			SDL_Event e;
			bool running = true;
			while(running) {
				while(SDL_PollEvent(&e))
					if(e.type == SDL_QUIT)
						running = false;
			}
		} else {
			printf("Window could not be created: %s\n", SDL_GetError());
		}
	} else {
		printf("SDL initialize failure: %s\n", SDL_GetError());
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}