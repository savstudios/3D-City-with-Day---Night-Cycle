#include "include.h"
#include "classes.h"

Game::Game(){};

void Game::Update(GLuint shaderProgram, GLuint vao, GLFWwindow* window){

   glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   glUseProgram(shaderProgram);

   glBindVertexArray(vao);
   glDrawArrays(GL_TRIANGLES, 0, 3);

   glfwSwapBuffers(window);
   glfwPollEvents();
};