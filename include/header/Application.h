#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Application{

   public:
      GLFWwindow* window;
      int width;
      int height;
      const char *name;

      Application(int width, int height, const char* name);

      void initAll();
      int createWindow();
      void terminateAll();
      static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};