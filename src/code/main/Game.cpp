#include "include.h"
#include "classes.h"

Game::Game(){};

void Game::Update(GLuint shaderProgram, GLuint vao, GLFWwindow* window){

   glClearColor(0.1f, 1.0f, 0.2f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   glUseProgram(shaderProgram);

   float time = glfwGetTime();
   float greenVal = std::sin(time) / 2.0f + 0.5f;
   int vertColorLoc = glGetUniformLocation(shaderProgram, "ourColor");
   glUniform4f(vertColorLoc, 0.0f, greenVal, 0.0f, 1.0f);

   glBindVertexArray(vao);
   glDrawArrays(GL_TRIANGLES, 0, 3);

   glfwSwapBuffers(window);
   glfwPollEvents();
};