#include "classes.h"
#include "include.h"

int success;
char infoLog[512];

Renderer::Renderer(){
   vertexShader = glCreateShader(GL_VERTEX_SHADER);
   fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
   shaderProgram = glCreateProgram();
}

void Renderer::genBuffers(unsigned int amnt, unsigned int* array){
   glGenBuffers(amnt, array);
}

void Renderer::bindBuffers(GLuint array){
   glBindBuffer(GL_ARRAY_BUFFER, array);
}

void Renderer::bufferData(int sizeOfArray, const void* array, int drawType){
   glBufferData(GL_ARRAY_BUFFER, sizeOfArray, array, drawType);
}

void Renderer::compileShader(unsigned int shader, const char* shaderSource){
   glShaderSource(shader, 1, &shaderSource, NULL);
   glCompileShader(shader);

   glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

   if(!success)
   {
    glGetShaderInfoLog(shader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
   }
}

void Renderer::attachAndLinkShader(){
   glAttachShader(shaderProgram, vertexShader);
   glAttachShader(shaderProgram, fragmentShader);
   glLinkProgram(shaderProgram);


   glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
   if(!success) {
      glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
   } 
}

void Renderer::deleteShaders(){
   glDeleteShader(vertexShader);
   glDeleteShader(fragmentShader);
}

void Renderer::linkVertAttributes(int location, int size, int stride, const void* offset){
   glVertexAttribPointer(location, size, GL_FLOAT, GL_FALSE, stride, offset);
   glEnableVertexAttribArray(0);
}

void Renderer::genVertArrays(unsigned int amnt, unsigned int* array){
   glGenVertexArrays(amnt, array);
}