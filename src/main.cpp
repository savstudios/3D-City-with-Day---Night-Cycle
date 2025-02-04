#include "include.h"
#include "classes.h"


int WinMain(int argc, char** argv[]){

   Application app(640, 480, "Hello, window!");
   app.initAll();
   app.createWindow();

   Game game;
   Renderer renderer;

   glfwSetFramebufferSizeCallback(app.window, app.framebuffer_size_callback);

   Shader shader("src/assets/shaders/shader.vert", "src/assets/shaders/shader.frag");

   renderer.genAndBindTextures(renderer.texture, 1);
   renderer.getTextureData("src/assets/images/crate.png");
   renderer.genTexture();

   renderer.genVertArrays(1, &renderer.vao);
   renderer.genBuffers(1, &renderer.vbo);
   glBindVertexArray(renderer.vao);
   renderer.bindBuffers(renderer.vbo);
   renderer.bufferData(sizeof(renderer.verts), renderer.verts, GL_STATIC_DRAW);
   renderer.linkVertAttributes(0, 3, 8 * sizeof(float), (void*)0);
   renderer.linkVertAttributes(1, 3, 8 * sizeof(float), (void*)(3 * sizeof(float)));
   renderer.linkVertAttributes(2, 2, 8 * sizeof(float), (void*)(6 * sizeof(float)));

   while(!glfwWindowShouldClose(app.window)){
      game.Update(shader.Shader_ID, renderer.vao, app.window, renderer.texture);
   }

   app.terminateAll();

   return 0;

}