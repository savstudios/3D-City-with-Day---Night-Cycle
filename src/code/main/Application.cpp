#include "include.h"
#include "header/Application.h"

Application::Application(){};

void Application::initAll(){

   // Init GLFW
   glfwInit();

   // Window hints
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

   // Init glad

   gladLoadGL();
};

int Application::createWindow(){
   Application::window = glfwCreateWindow(
      Application::width,
      Application::height,
      Application::name,
      NULL,
      NULL
   );

   if(!window){
      std::cout << "Failed to create a window!" << std::endl;
      glfwTerminate();
      return -1;
   }

   return 0;
}