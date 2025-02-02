#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer{
   public:

      float verts[9] = {
         -0.5f, -0.5f, 0.0f, // Bottom left
          0.5f, -0.5f, 0.0f, // Bottom right
          0.0f,  0.5f, 0.0f // Top middle
      };

      const char *vertexShaderSource = "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\0";

      const char *fragmentShaderSource = "#version 330 core\n"
      "out vec4 FragColor;\n"
      "void main()"
      "{\n"
      "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
      "}\n";

      GLuint vbo, vao;
      GLuint vertexShader;
      GLuint fragmentShader;
      GLuint shaderProgram;

      Renderer();

      void changeScreenColor(float r, float g, float b, float a, GLFWwindow* window);
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