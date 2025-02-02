#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game{

   public:

      Game();

      void Update(GLuint shaderProgram, GLuint vao, GLFWwindow* window);
};