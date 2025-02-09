#include "include.h"
#include "classes.h"

Game::Game(){};

void Game::Update(GLuint shaderProgram, GLuint vao, GLFWwindow* window, unsigned int texture, GLuint transformUniLoc){

   glm::mat4 trans = glm::mat4(1.0f);
   trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0, 0.0, 1.0));
   trans = glm::translate(trans, glm::vec3(0.5, -0.5, 0.0));

   glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   glUseProgram(shaderProgram);
   glUniformMatrix4fv(transformUniLoc, 1, GL_FALSE, glm::value_ptr(trans));

   glBindTexture(GL_TEXTURE_2D, texture);
   glBindVertexArray(vao);
   glDrawArrays(GL_TRIANGLES, 0, 6);

   glfwSwapBuffers(window);
   glfwPollEvents();
};