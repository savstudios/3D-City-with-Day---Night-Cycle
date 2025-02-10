#include "include.h"
#include "classes.h"

Game::Game(){};

void Game::Update(GLFWwindow* window){

   std::cout << "Updated!\n";
   glfwPollEvents();
   this -> processInput(window);
   this -> calculateDeltaTime();
};

void Game::processInput(GLFWwindow* window){
   std::cout << "Calculating Input!\n";
   if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){ std::cout << "W key\n"; camera.position += camera.speed * camera.front; }
   if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){ std::cout << "S key\n"; camera.position -= camera.speed * camera.front; }
   if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){ std::cout << "A key\n"; camera.position -= glm::normalize(glm::cross(camera.front, camera.up)) * camera.speed; }
   if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){ std::cout << "D key\n"; camera.position += glm::normalize(glm::cross(camera.front, camera.up)) * camera.speed; }
}

void Game::calculateDeltaTime(){
   std::cout << "Calculating DT!\n";
   float currentFrame = glfwGetTime();
   this -> deltaTime = currentFrame - this -> lastFrame;
   this -> lastFrame = currentFrame;
   std::cout << this -> deltaTime;
   camera.speed = 2.5f * this -> deltaTime;
}