#pragma once

#ifndef SHADER_H
#define SHADER_H

#include "include.h"

class Shader{
   public:
      unsigned int Shader_ID;

      Shader(const char* vertexPath, const char* fragmentPath);

      void use();

      void setBool(const std::string &name, bool val) const;
      void setInt(const std::string &name, int val) const;
      void setFloat(const std::string &name, float val) const;
};

#endif