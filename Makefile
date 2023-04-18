# define the source files
SRCS := $(wildcard *.cpp)

# define the object files
OBJS := $(patsubst %.cpp, %.o, $(SRCS))

# define the compiler
CC = g++

# define the compiler flags
CFLAGS = -Wall -Wextra -pedantic -std=c++11

# define the include paths
INCLUDE_PATHS = -IC:\mingw_lib\sdl2\include\SDL2

# define the library paths
LIBRARY_PATHS = -LC:\mingw_lib\sdl2\lib

# define the linker flags
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

# define the target executable
TARGET = game

# build rule for object files
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE_PATHS) -c -o $@ $<

# build rule for the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $(TARGET)

# clean rule
clean:
	rm -f $(OBJS) $(TARGET)
