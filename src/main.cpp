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
   Shader lightShader("src/assets/shaders/light.vert", "src/assets/shaders/light.frag");
   
   renderer.genAndBindTextures(renderer.texture, 1);
   renderer.getTextureData("src/assets/images/crate.png");
   renderer.genTexture();
   
   renderer.genVertArrays(1, &renderer.vao);
   renderer.genBuffers(1, &renderer.vbo);
   glBindVertexArray(renderer.vao);
   renderer.bindBuffers(renderer.vbo);
   renderer.bufferData(sizeof(renderer.verts), renderer.verts, GL_STATIC_DRAW);
   renderer.linkVertAttributes(0, 3, 6 * sizeof(float), (void*)0);
   renderer.linkVertAttributes(1, 3, 6 * sizeof(float), (void*)(3 * sizeof(float)));

   GLuint lightVAO;
   renderer.genVertArrays(1, &lightVAO);
   glBindVertexArray(lightVAO);
   glBindBuffer(GL_ARRAY_BUFFER, renderer.vbo);
   renderer.linkVertAttributes(0, 3, 6 * sizeof(float), (void*)0);
   

   while(!glfwWindowShouldClose(app.window)){

      glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      shader.use();
      
      glUniform3f(glGetUniformLocation(shader.Shader_ID, "lightColor"), 1.0f, 1.0f, 1.0f);
      glUniform3f(glGetUniformLocation(shader.Shader_ID, "objColor"), 1.0f, 0.5f, 0.31f);
      glUniform3fv(glGetUniformLocation(shader.Shader_ID, "lightPos"), 1, &renderer.lightPos[0]);
      glUniform3fv(glGetUniformLocation(shader.Shader_ID, "viewPos"), 1, &camera.position[0]);
      
      glBindTexture(GL_TEXTURE_2D, renderer.texture);
      
      renderer.model = glm::mat4(1.0f);
      renderer.view = glm::mat4(1.0f);
      
      renderer.view = glm::lookAt(
         camera.position,
         camera.position + camera.front,
         camera.up
      );
      
      GLuint MVPloc = renderer.getUniformLocation(shader.Shader_ID, "viewProjModel");
      GLuint cubeModelLoc = renderer.getUniformLocation(shader.Shader_ID, "model");
      glm::mat4 MVP = renderer.proj * renderer.view * renderer.model;
      glUniformMatrix4fv(MVPloc, 1, GL_FALSE, glm::value_ptr(MVP));
      glUniformMatrix4fv(cubeModelLoc, 1, GL_FALSE, glm::value_ptr(renderer.model));

      glBindVertexArray(renderer.vao);
      glDrawArrays(GL_TRIANGLES, 0, 36);
      
      lightShader.use();
      glm::mat4 lightModel = glm::mat4(1.0f);
      lightModel = glm::translate(lightModel, renderer.lightPos);
      lightModel = glm::scale(lightModel, glm::vec3(0.2f));
      
      GLuint lightMVPloc = renderer.getUniformLocation(lightShader.Shader_ID, "viewProjModel");
      glm::mat4 lightMVP = renderer.proj * renderer.view * lightModel;
      glUniformMatrix4fv(lightMVPloc, 1, GL_FALSE, glm::value_ptr(lightMVP));

      
      glBindVertexArray(lightVAO);
      glDrawArrays(GL_TRIANGLES, 0, 36);
   
      glfwSwapBuffers(app.window);

      game.Update(app.window);

   }

   app.terminateAll();

   return 0;

}