#include "include.h"
#include "classes.h"


int WinMain(int argc, char** argv[]){

   Application app(640, 480, "Hello, window!");
   Game game;

   app.initAll();
   app.createWindow();

   while(!glfwWindowShouldClose(app.window)){
      game.Update();
   }

   app.terminateAll();

   return 0;

}