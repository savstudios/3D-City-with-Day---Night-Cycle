#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include "include.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer{
   public:

      float verts[1000] = {
         //      Verts       //
         
         // Front Face
         -0.5f, -0.5f,  0.5f, // Bottom left
          0.5f, -0.5f,  0.5f, // Bottom right
         -0.5f,  0.5f,  0.5f, // Top left

         -0.5f,  0.5f,  0.5f, // Top left
          0.5f,  0.5f,  0.5f, // Top right
          0.5f, -0.5f,  0.5f, // Bottom right

          // Back Face
         -0.5f, -0.5f, -0.5f, // Bottom left
          0.5f, -0.5f, -0.5f, // Bottom right
         -0.5f,  0.5f, -0.5f, // Top left

         -0.5f,  0.5f, -0.5f, // Top left
          0.5f,  0.5f, -0.5f, // Top right
          0.5f, -0.5f, -0.5f, // Bottom right

         // Top Face
         -0.5f,  0.5f,  0.5f, // Bottom left
          0.5f,  0.5f,  0.5f, // Bottom right
         -0.5f,  0.5f, -0.5f, // Top left

         -0.5f,  0.5f, -0.5f, // Top left
          0.5f,  0.5f, -0.5f, // Top right
          0.5f,  0.5f,  0.5f, // Bottom right

         // Bottom Face
         -0.5f, -0.5f,  0.5f, // Bottom left
          0.5f, -0.5f,  0.5f, // Bottom right
         -0.5f, -0.5f, -0.5f, // Top left

         -0.5f, -0.5f, -0.5f, // Top left
          0.5f, -0.5f, -0.5f, // Top right
          0.5f, -0.5f,  0.5f, // Bottom right

         // Left Face
         -0.5f, -0.5f, -0.5f, // Bottom left
         -0.5f, -0.5f,  0.5f, // Bottom right
         -0.5f,  0.5f, -0.5f, // Top left

         -0.5f,  0.5f, -0.5f, // Top left
         -0.5f,  0.5f,  0.5f, // Top right
         -0.5f, -0.5f,  0.5f, // Bottom right

         // Right Face
          0.5f, -0.5f, -0.5f, // Bottom left
          0.5f, -0.5f,  0.5f, // Bottom right
          0.5f,  0.5f, -0.5f, // Top left

          0.5f,  0.5f, -0.5f, // Top left
          0.5f,  0.5f,  0.5f, // Top right
          0.5f, -0.5f,  0.5f, // Bottom right
      };

      glm::vec3 lightPos = glm::vec3(1.2f, 1.0f, 2.0f);

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