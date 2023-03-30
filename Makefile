#EXE_NAME specifies the name of the executable 
EXE_NAME = test

SDL_PATH = -IC:\mingw_lib\sdl2\include\SDL2
SDL_LIBRARY = -LC:\mingw_lib\sdl2\lib

# -w suppresses warnings
COMPILER_FLAGS = -Wall -Wextra -pedantic -std=c++11

LINK_FLAGS = -lSDL2

COMPILER = g++

$(EXE_NAME): main.o init.o
	$(COMPILER) $(COMPILER_FLAGS) $(SDL_PATH) $(SDL_LIBRARY) $(LINK_FLAGS) $^ -o $@ $(SDL_LIBRARY)

main.o: main.cpp init.h
	$(COMPILER) $(COMPILER_FLAGS) $(SDL_PATH) $(SDL_LIBRARY) $(LINK_FLAGS) -c main.cpp

init.o: init.cpp init.h defs.h
	$(COMPILER) $(COMPILER_FLAGS) $(SDL_PATH) $(SDL_LIBRARY) $(LINK_FLAGS) -c init.cpp

.PHONY: clean
clean:
	rm *.o