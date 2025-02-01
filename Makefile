all:
	g++ -o Game src/main.cpp src/glad.c src/code/main/Application.cpp src/code/main/Game.cpp -Iinclude -Llib -lglfw3dll