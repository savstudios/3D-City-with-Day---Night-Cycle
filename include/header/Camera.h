#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "include.h"

class Camera{
   public:

      Camera();

      // How much the camera moves every frame
      float speed = 2.5f * game.deltaTime;

      // Camera Vectors
      glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f);
      glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f);
      glm::vec3 direction = glm::normalize(position - target);
      glm::vec3 right = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), direction));
      glm::vec3 up = glm::cross(direction, right);
      glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
};

extern Camera camera;

#endif