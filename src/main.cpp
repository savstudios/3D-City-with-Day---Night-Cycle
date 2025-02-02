#include "include.h"
#include "classes.h"


int WinMain(int argc, char** argv[]){

   Application app(640, 480, "Hello, window!");
   Renderer renderer;
   Game game;

   app.initAll();
   app.createWindow();

   renderer.genBuffers(1, &renderer.vbo);
   renderer.bindBuffers(renderer.vbo);
   renderer.bufferData(sizeof(renderer.verts), renderer.verts, GL_STATIC_DRAW);
   renderer.genVertArrays(1, &renderer.vao);
   renderer.linkVertAttributes(0, 3, 3 * sizeof(float), (void*)0);
   renderer.compileShader(renderer.vertexShader, renderer.vertexShaderSource);
   renderer.compileShader(renderer.fragmentShader, renderer.fragmentShaderSource);
   renderer.attachAndLinkShader();
   renderer.deleteShaders();


   while(!glfwWindowShouldClose(app.window)){
      game.Update();
      renderer.changeScreenColor(0.1f, 1.0f, 0.4f, 1.0f, app.window);
   }

   app.terminateAll();

   return 0;

}