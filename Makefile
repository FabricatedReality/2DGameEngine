#EXE_NAME specifies the name of the executable 
EXE_NAME = test

SDL_PATH = -IC:\mingw_lib\sdl2\include\SDL2
SDL_LIBRARY = -LC:\mingw_lib\sdl2\lib

# -w suppresses warnings
COMPILER_FLAGS = -w
LINK_FLAGS = -lmingw32 -lSDL2main -lSDL2

FILES = main.cpp app.cpp

COMPILER = g++

all : $(FILES)
	$(COMPILER) $(FILES) $(SDL_PATH) $(SDL_LIBRARY) $(COMPILER_FLAGS) $(LINK_FLAGS) -o $(EXE_NAME)