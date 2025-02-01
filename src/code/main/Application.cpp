#include "include.h"
#include "header/Application.h"

Application::Application(int width, int height, const char* name){
   Application::width = width;
   Application::height = height;
   Application::name = name;
};

void Application::initAll(){

   // Init GLFW
   glfwInit();

   // Window hints
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

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

   glfwMakeContextCurrent(window);

   // Init glad

   gladLoadGL();

   glViewport(0, 0, Application::width, Application::height);

   return 0;
}

void Application::terminateAll(){
   glfwDestroyWindow(window);
   glfwTerminate();
}