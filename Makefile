# Source Code paths

CODE = src/main.cpp\
		 src/glad.c\
		 src/code/other/stb_image.cpp\
		 src/code/main/Application.cpp\
		 src/code/main/Game.cpp\
		 src/code/main/Renderer.cpp\
		 src/code/main/Shader.cpp\
		 src/code/main/Camera.cpp\

all:
	g++ -Wall -g -o Game $(CODE) -Iinclude -Llib -lglfw3dll

clean:
	rm -f *.o Game