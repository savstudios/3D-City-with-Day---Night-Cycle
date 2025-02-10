#pragma once

#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game{

   public:

      float deltaTime = 0.0f;
      float lastFrame = 0.0f;

      Game();

      void Update(GLFWwindow* window);
      void processInput(GLFWwindow* window);
      static void processMouseInput(GLFWwindow* window, double xPos, double yPos);
      void calculateDeltaTime();
};

extern Game game;

#endif