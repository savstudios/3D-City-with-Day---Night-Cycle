#include "include.h"
#include "classes.h"


int WinMain(int argc, char** argv[]){

   Application app(640, 480, "Hello, window!");
   Renderer renderer;
   Game game;

   app.initAll();
   app.createWindow();

   while(!glfwWindowShouldClose(app.window)){
      game.Update();
      renderer.changeScreenColor(0.1f, 1.0f, 0.4f, 1.0f, app.window);
   }

   app.terminateAll();

   return 0;

}