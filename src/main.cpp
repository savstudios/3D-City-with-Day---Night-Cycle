#include "include.h"
#include "classes.h"

Game game;

int WinMain(int argc, char** argv[]){

   Application app(640, 480, "Hello, window!");
   app.initAll();
   app.createWindow();

   Renderer renderer(app.width, app.height);
   
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
   renderer.linkVertAttributes(0, 3, 5 * sizeof(float), (void*)0);
   renderer.linkVertAttributes(1, 2, 5 * sizeof(float), (void*)(3 * sizeof(float)));
   

   while(!glfwWindowShouldClose(app.window)){

      glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      shader.use();

      glBindTexture(GL_TEXTURE_2D, renderer.texture);

      renderer.model = glm::mat4(1.0f);
      renderer.view = glm::mat4(1.0f);

      renderer.view = glm::lookAt(
         camera.position,
         camera.position + camera.front,
         camera.up
      );

      GLuint MVPloc = renderer.getUniformLocation(shader.Shader_ID, "viewProjModel");

      glBindVertexArray(renderer.vao);
      for(unsigned int i = 0; i < 10; i++)
      {
         renderer.model = glm::mat4(1.0f);
         renderer.model = glm::translate(renderer.model, renderer.cubePositions[i]);

         float angle = 20.0f * i; 

         renderer.model = glm::rotate(renderer.model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
         
         glm::mat4 MVP = renderer.proj * renderer.view * renderer.model;
         glUniformMatrix4fv(MVPloc, 1, GL_FALSE, glm::value_ptr(MVP));
      
         glDrawArrays(GL_TRIANGLES, 0, 36);
      }
      glDrawArrays(GL_TRIANGLES, 0, 36);
   
      glfwSwapBuffers(app.window);

      game.Update(app.window);

   }

   app.terminateAll();

   return 0;

}