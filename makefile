FILE = $(addsuffix .cpp, $(N))
EXECUTABLE = $(N)
COPILER = g++
LIBS = -lGL -lGLU -lGLEW -lglut
FLAGS = -lm -Wno-write-strings

all:
	$(COPILER) $(FILE) -o $(EXECUTABLE) $(LIBS) $(FLAGS)

	./$(EXECUTABLE)
