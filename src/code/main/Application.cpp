#include "include.h"
#include "header/Application.h"

Application::Application(int width, int height, const char* name){
   this -> width = width;
   this -> height = height;
   this -> name = name;
};

void Application::initAll(){

   std::cout << "Initalizing!";

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

void Application::framebuffer_size_callback(GLFWwindow* window, int width, int height){
   glViewport(0, 0, width, height);
}