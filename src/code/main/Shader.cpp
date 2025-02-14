#include "classes.h"
#include "include.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath){

   Renderer renderer(640, 480);
   
   std::string vertexCode;
   std::string fragmentCode;
   std::ifstream vertexShaderFile;
   std::ifstream fragmentShaderFile;

   vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
   fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

   try {
      // Open the files
      vertexShaderFile.open(vertexPath);
      fragmentShaderFile.open(fragmentPath);

      std::stringstream vertexShaderStream, fragmentShaderStream;

      // Read the buffers
      vertexShaderStream << vertexShaderFile.rdbuf();
      fragmentShaderStream << fragmentShaderFile.rdbuf();

      // Close the file
      vertexShaderFile.close();
      fragmentShaderFile.close();

      // Convert to string
      vertexCode = vertexShaderStream.str();
      fragmentCode = fragmentShaderStream.str();
   }
   catch(std::ifstream::failure e){
      std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
   }
   // Get the string and convert it into characters
   const char* vertexShaderCode = vertexCode.c_str();
   const char* fragmentShaderCode = fragmentCode.c_str();

   renderer.compileShader(renderer.vertexShader, vertexShaderCode);
   renderer.compileShader(renderer.fragmentShader, fragmentShaderCode);
   renderer.attachAndLinkShader();

   Shader_ID = renderer.shaderProgram;

   renderer.deleteShaders();
}

void Shader::use(){
   glUseProgram(Shader_ID);
}

void Shader::setBool(const std::string &name, bool val) const{
   glUniform1i(glGetUniformLocation(Shader_ID, name.c_str()), (int)val);
}

void Shader::setInt(const std::string &name, int val) const{
   glUniform1i(glGetUniformLocation(Shader_ID, name.c_str()), val);
}

void Shader::setFloat(const std::string &name, float val) const{
   glUniform1f(glGetUniformLocation(Shader_ID, name.c_str()), val);
}

void Shader::setVec3(const std::string &name, float x, float y, float z){
   glUniform3f(glGetUniformLocation(Shader_ID, name.c_str()), x, y, z);
}

void Shader::setVec3(const std::string &name, glm::vec3 &vector){
   glUniform3fv(glGetUniformLocation(Shader_ID, name.c_str()), 1, &vector[0]);
}

void Shader::setMat4(const std::string &name, glm::mat4 &matrix){
   glUniformMatrix4fv(glGetUniformLocation(Shader_ID, name.c_str()), 1, GL_FALSE, &matrix[0][0]);
}