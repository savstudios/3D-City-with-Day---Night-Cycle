#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer{
   public:

      float verts[18] = {
         //      Verts     //    
         -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // Bottom left
          0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // Bottom right
          0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f  // Top middle
      };

      GLuint vbo, vao;
      GLuint vertexShader, fragmentShader;
      GLuint shaderProgram;
      GLuint texture;

      Renderer();

      void genBuffers(unsigned int amnt, unsigned int* array);
      void genVertArrays(unsigned int amnt, unsigned int* array);
      void bindBuffers(GLuint array);
      void bufferData(int sizeOfArray, const void* array, int drawType);
      void compileShader(unsigned int shader, const char* shaderSource);
      void attachAndLinkShader();
      void linkVertAttributes(int location, int size, int stride, const void* offset);

      void deleteShaders();

   private:
};

extern Renderer renderer;