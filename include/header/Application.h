#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Application{

   public:
      GLFWwindow* window;
      int width;
      int height;
      const char *name;

      Application();

      void initAll();
      int createWindow();
};