#include "include.h"
#include "classes.h"

Game::Game(){};

void Game::Update(GLFWwindow* window){
   glfwPollEvents();
   this -> processInput(window);
   this -> calculateDeltaTime();
};

void Game::processInput(GLFWwindow* window){
   // Camera Movement
   if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){ camera.position += camera.speed * camera.front; }
   if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){ camera.position -= camera.speed * camera.front; }
   if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){ camera.position -= glm::normalize(glm::cross(camera.front, camera.up)) * camera.speed; }
   if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){ camera.position += glm::normalize(glm::cross(camera.front, camera.up)) * camera.speed; }

   // Exiting Game
   if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){ glfwDestroyWindow(window); glfwTerminate(); }
}

void Game::processMouseInput(GLFWwindow* window, double xPos, double yPos){

   if(camera.firstMouse){
      camera.lastX = xPos;
      camera.lastY = yPos;
      camera.firstMouse = false;
   }

   float xOffset = xPos - camera.lastX;
   float yOffset = camera.lastY - yPos;

   camera.lastX = xPos;
   camera.lastY = yPos;

   xOffset *= camera.sensitivity;
   yOffset *= camera.sensitivity;

   camera.yaw += xOffset;
   camera.pitch += yOffset;

   if(camera.pitch > 89.0f) camera.pitch = 89.0f;
   if(camera.pitch < -89.0f) camera.pitch = -89.0f;

   glm::vec3 direction;
   direction.x = cos(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
   direction.y = sin(glm::radians(camera.pitch));
   direction.z = sin(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));

   camera.front = glm::normalize(direction);
}

void Game::calculateDeltaTime(){
   float currentFrame = glfwGetTime();
   this -> deltaTime = currentFrame - this -> lastFrame;
   this -> lastFrame = currentFrame;
   camera.speed = 2.5f * this -> deltaTime;
}