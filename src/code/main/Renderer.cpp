#include "classes.h"
#include "include.h"

int success;
char infoLog[512];


Renderer::Renderer(int width, int height){

   this -> vertexShader = glCreateShader(GL_VERTEX_SHADER);
   this -> fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
   this -> shaderProgram = glCreateProgram();

   this -> proj = glm::mat4(1.0f);
   this -> model = glm::mat4(1.0f);
   this -> view = glm::mat4(1.0f);

   this -> model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
   this -> view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
   this -> proj = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);

   // * Params

   glEnable(GL_DEPTH_TEST);

   // TEXTURE PARAMRS

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   // STBI

   stbi_set_flip_vertically_on_load(true);
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
   glEnableVertexAttribArray(location);
}

void Renderer::genVertArrays(unsigned int amnt, unsigned int* array){
   glGenVertexArrays(amnt, array);
}

unsigned int Renderer::genTexture(const char* filePath){

   unsigned int texture;
   glGenTextures(1, &texture);

   int width, height, numChannels;
   unsigned char* data = stbi_load(filePath, &width, &height, &numChannels, 0);

   if( data ){

      GLenum format;
      switch (numChannels){
         case 1:
            format = GL_RED; break;
         case 3:
            format = GL_RGB; break;
         case 4:
            format = GL_RGBA; break;
      }

      glBindTexture(GL_TEXTURE_2D, texture);
      glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
      glGenerateMipmap(GL_TEXTURE_2D);
   }
   else{
      std::cout << "Whoops, oh sh1t! Your texture weren't generated lol" << std::endl;
   }

   stbi_image_free(data);

   return texture;
}

GLint Renderer::getUniformLocation(GLuint shaderID, const char* name){
   return glGetUniformLocation(shaderID, name);
}