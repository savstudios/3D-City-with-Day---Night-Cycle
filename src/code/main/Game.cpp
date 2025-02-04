#include "include.h"
#include "classes.h"

Game::Game(){};

void Game::Update(GLuint shaderProgram, GLuint vao, GLFWwindow* window, unsigned int texture){

   glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   glUseProgram(shaderProgram);

   glBindTexture(GL_TEXTURE_2D, texture);
   glBindVertexArray(vao);
   glDrawArrays(GL_TRIANGLES, 0, 6);

   glfwSwapBuffers(window);
   glfwPollEvents();
};