#pragma once

#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game{

   public:

      Game();

      void Update(GLuint shaderProgram, GLuint vao, GLFWwindow* window, unsigned int texture, GLuint transformUniLoc);
};

#endif