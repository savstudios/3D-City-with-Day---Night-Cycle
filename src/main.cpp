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

      GLenum err;
      while ((err = glGetError()) != GL_NO_ERROR) {
         std::cout << "OpenGL error: " << err << std::endl;
      }

      glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      shader.use();

      glBindTexture(GL_TEXTURE_2D, renderer.texture);

      GLuint MVPloc = renderer.getUniformLocation(shader.Shader_ID, "viewProjModel");
      glm::mat4 MVP = renderer.proj * renderer.view * renderer.model;
      glUniformMatrix4fv(MVPloc, 1, GL_FALSE, glm::value_ptr(MVP));

      glBindVertexArray(renderer.vao);
      glDrawArrays(GL_TRIANGLES, 0, 6);
   
      glfwSwapBuffers(app.window);

      game.Update();

   }

   app.terminateAll();

   return 0;

}