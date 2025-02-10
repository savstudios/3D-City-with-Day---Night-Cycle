#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include "include.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer{
   public:

      float verts[1000] = {
         //      Verts       //  Textures  // 
         
         // Front Face
         -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, // Bottom left
          0.5f, -0.5f,  0.5f,  1.0f, 1.0f, // Bottom right
         -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, // Top left

         -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, // Top left
          0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // Top right
          0.5f, -0.5f,  0.5f,  1.0f, 1.0f, // Bottom right

          // Back Face
         -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // Bottom left
          0.5f, -0.5f, -0.5f,  1.0f, 1.0f, // Bottom right
         -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, // Top left

         -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, // Top left
          0.5f,  0.5f, -0.5f,  1.0f, 0.0f, // Top right
          0.5f, -0.5f, -0.5f,  1.0f, 1.0f, // Bottom right

         // Top Face
         -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, // Bottom left
          0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // Bottom right
         -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, // Top left

         -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, // Top left
          0.5f,  0.5f, -0.5f,  1.0f, 0.0f, // Top right
          0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // Bottom right

         // Bottom Face
         -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, // Bottom left
          0.5f, -0.5f,  0.5f,  1.0f, 1.0f, // Bottom right
         -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Top left

         -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Top left
          0.5f, -0.5f, -0.5f,  1.0f, 0.0f, // Top right
          0.5f, -0.5f,  0.5f,  1.0f, 1.0f, // Bottom right

         // Left Face
         -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // Bottom left
         -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, // Bottom right
         -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, // Top left

         -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, // Top left
         -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // Top right
         -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, // Bottom right

         // Right Face
          0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // Bottom left
          0.5f, -0.5f,  0.5f,  1.0f, 1.0f, // Bottom right
          0.5f,  0.5f, -0.5f,  0.0f, 0.0f, // Top left

          0.5f,  0.5f, -0.5f,  0.0f, 0.0f, // Top left
          0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // Top right
          0.5f, -0.5f,  0.5f,  1.0f, 1.0f, // Bottom right
      };

      glm::vec3 cubePositions[10] = {
         glm::vec3( 0.0f,  0.0f,  0.0f), 
         glm::vec3( 2.0f,  5.0f, -15.0f), 
         glm::vec3(-1.5f, -2.2f, -2.5f),  
         glm::vec3(-3.8f, -2.0f, -12.3f),  
         glm::vec3( 2.4f, -0.4f, -3.5f),  
         glm::vec3(-1.7f,  3.0f, -7.5f),  
         glm::vec3( 1.3f, -2.0f, -2.5f),  
         glm::vec3( 1.5f,  2.0f, -2.5f), 
         glm::vec3( 1.5f,  0.2f, -1.5f), 
         glm::vec3(-1.3f,  1.0f, -1.5f)  
     };

      GLuint vbo, vao;
      GLuint vertexShader, fragmentShader;
      GLuint shaderProgram;
      GLuint texture;

      glm::mat4 proj;
      glm::mat4 model;
      glm::mat4 view;

      int width, height, numChannels;
      unsigned char* data;

      Renderer(int width, int height);

      void genBuffers(unsigned int amnt, unsigned int* array);
      void genVertArrays(unsigned int amnt, unsigned int* array);
      void bindBuffers(GLuint array);
      void bufferData(int sizeOfArray, const void* array, int drawType);
      void compileShader(unsigned int shader, const char* shaderSource);
      void attachAndLinkShader();
      void linkVertAttributes(int location, int size, int stride, const void* offset);

      // TEXTURES

      void genAndBindTextures(GLuint& texture, int amnt);
      void getTextureData(const char* filePath);
      void genTexture();

      // Shaders

      GLint getUniformLocation(GLuint shaderID, const char* name);

      // GLM

      glm::mat4 translateMat4(glm::mat4 matrix, glm::vec3 vector);

      void deleteShaders();

   private:
};

extern Renderer renderer;

#endif