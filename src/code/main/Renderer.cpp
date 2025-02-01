#include "classes.h"
#include "include.h"

Renderer::Renderer(){}

void Renderer::changeScreenColor(float r, float g, float b, float a, GLFWwindow* window){
   glClearColor(r, g, b, a);
   glClear(GL_COLOR_BUFFER_BIT);
   glfwSwapBuffers(window);
}