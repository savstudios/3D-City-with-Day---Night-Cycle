#include "include.h"
#include "classes.h"


int WinMain(int argc, char** argv[]){

   Application app(640, 480, "Hello, window!");
   app.initAll();
   app.createWindow();

   Renderer renderer;
   Game game;

   renderer.compileShader(renderer.vertexShader, renderer.vertexShaderSource);
   renderer.compileShader(renderer.fragmentShader, renderer.fragmentShaderSource);
   renderer.attachAndLinkShader();
   renderer.deleteShaders();
   renderer.genVertArrays(1, &renderer.vao);
   renderer.genBuffers(1, &renderer.vbo);
   glBindVertexArray(renderer.vao);
   renderer.bindBuffers(renderer.vbo);
   renderer.bufferData(sizeof(renderer.verts), renderer.verts, GL_STATIC_DRAW);
   renderer.linkVertAttributes(0, 3, 3 * sizeof(float), (void*)0);


   while(!glfwWindowShouldClose(app.window)){
      game.Update(renderer.shaderProgram, renderer.vao, app.window);
   }

   app.terminateAll();

   return 0;

}