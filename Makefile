all:
	g++ -o Game src/main.cpp src/glad.c src/code/main/Application.cpp src/code/main/Game.cpp src/code/main/Renderer.cpp src/code/main/Shader.cpp -Iinclude -Llib -lglfw3dll