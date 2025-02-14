#pragma once

#ifndef SHADER_H
#define SHADER_H

#include "include.h"

class Shader{
   public:
      unsigned int Shader_ID;

      Shader(const char* vertexPath, const char* fragmentPath);

      void use();

      // 'set' Functions
      void setBool(const std::string &name, bool val) const;
      void setInt(const std::string &name, int val) const;
      void setFloat(const std::string &name, float val) const;

      void setVec3(const std::string &name, float x, float y, float z);
      void setVec3(const std::string &name, glm::vec3 &vector);
      void setMat4(const std::string &name, glm::mat4 &matrix);
};

#endif