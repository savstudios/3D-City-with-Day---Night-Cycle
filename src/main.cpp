#include "include.h"
#include "classes.h"

Game game;

int WinMain(int argc, char** argv[]){

   Application app(1280, 960, "Hello, window!");
   app.initAll();
   app.createWindow();

   Renderer renderer(app.width, app.height);
   
   glfwSetFramebufferSizeCallback(app.window, app.framebuffer_size_callback);
   
   Shader shader("src/assets/shaders/shader.vert", "src/assets/shaders/shader.frag");
   Shader lightShader("src/assets/shaders/light.vert", "src/assets/shaders/light.frag");

   unsigned int normalTex;
   unsigned int specularTex;

   normalTex = renderer.genTexture("src/assets/images/container2.png");
   specularTex = renderer.genTexture("src/assets/images/container2_specular.png");
   
   renderer.genVertArrays(1, &renderer.vao);
   renderer.genBuffers(1, &renderer.vbo);
   glBindVertexArray(renderer.vao);
   renderer.bindBuffers(renderer.vbo);
   renderer.bufferData(sizeof(renderer.verts), renderer.verts, GL_STATIC_DRAW);
   renderer.linkVertAttributes(0, 3, 8 * sizeof(float), (void*)0);
   renderer.linkVertAttributes(1, 3, 8 * sizeof(float), (void*)(3 * sizeof(float)));
   renderer.linkVertAttributes(2, 2, 8 * sizeof(float), (void*)(6 * sizeof(float)));

   GLuint lightVAO;
   renderer.genVertArrays(1, &lightVAO);
   glBindVertexArray(lightVAO);
   glBindBuffer(GL_ARRAY_BUFFER, renderer.vbo);
   renderer.linkVertAttributes(0, 3, 8 * sizeof(float), (void*)0);

   while(!glfwWindowShouldClose(app.window)){

      glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      shader.use();
      
      shader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
      shader.setVec3("objColor", 1.0f, 1.0f, 1.0f);
      shader.setVec3("lightPos", renderer.lightPos);
      shader.setVec3("viewPos", camera.position);

      shader.setVec3("material.ambient", 1.0f, 0.5f, 0.31f);
      shader.setVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
      shader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
      shader.setFloat("material.shininess", 32.0f);

      shader.setVec3("light.ambient", 0.1f, 0.1f, 0.1f);
      shader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
      shader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);

      shader.setInt("material.diffuse", 0);
      shader.setInt("material.specular", 1);
      
      renderer.model = glm::mat4(1.0f);
      renderer.view = glm::mat4(1.0f);
      
      renderer.view = glm::lookAt(
         camera.position,
         camera.position + camera.front,
         camera.up
      );
      
      glm::mat4 MVP = renderer.proj * renderer.view * renderer.model;
      shader.setMat4("viewProjModel", MVP);
      shader.setMat4("model", renderer.model);

      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, normalTex);
      glActiveTexture(GL_TEXTURE1);
      glBindTexture(GL_TEXTURE_2D, specularTex);

      glBindVertexArray(renderer.vao);
      glDrawArrays(GL_TRIANGLES, 0, 36);
      
      lightShader.use();
      glm::mat4 lightModel = glm::mat4(1.0f);
      lightModel = glm::translate(lightModel, renderer.lightPos);
      lightModel = glm::scale(lightModel, glm::vec3(0.2f));

      glm::mat4 lightMVP = renderer.proj * renderer.view * lightModel;
      lightShader.setMat4("viewProjModel", lightMVP);
      
      glBindVertexArray(lightVAO);
      glDrawArrays(GL_TRIANGLES, 0, 36);
   
      glfwSwapBuffers(app.window);

      game.Update(app.window);

   }

   app.terminateAll();

   return 0;

}