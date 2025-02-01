#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer{
   public:

      Renderer();

      void changeScreenColor(float r, float g, float b, float a, GLFWwindow* window);
};