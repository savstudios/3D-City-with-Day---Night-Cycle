CC=g++

all:
	$(CC) -o Game src/glad.c src/main.cpp src/code/main/Application.cpp src/code/main/Game.cpp src/code/main/Renderer.cpp -Iinclude -Llib -lglfw3dll