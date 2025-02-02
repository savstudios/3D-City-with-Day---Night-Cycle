#include "include.h"
#include "classes.h"

Game::Game(){};
Renderer renderer;

void Game::Update(){

   glfwPollEvents();

   glUseProgram(renderer.shaderProgram);
   glBindVertexArray(renderer.vao);
   glDrawArrays(GL_TRIANGLES, 0, 3);
};