cmake_minimum_required(VERSION 3.10)

# Project name
project(3D-CITY)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SRC_FILES
    src/main.cpp
    src/glad.c
    src/code/other/stb_image.cpp
    src/code/main/Application.cpp
    src/code/main/Camera.cpp
    src/code/main/Game.cpp
    src/code/main/Renderer.cpp
    src/code/main/Shader.cpp
)

# Include directories
include_directories(
    include
    include/glad
    include/GLFW
    include/glm
    include/header
    include/stb_image
)

# Set output path (aka where the .exe is)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

# Add executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Set GLFW path
set(GLFW_LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# Link OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

# Add GLFW manually for Windows
if (WIN32)
    include_directories(${GLFW_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} "${GLFW_LIB_DIR}/libglfw3dll.a")
endif()

# Add GLFW normally for Unix (Linux/macOS)
if (UNIX)
    find_package(glfw3 REQUIRED)
    target_link_libraries(${PROJECT_NAME} glfw)
endif()

# Copy assets to build directory
file(COPY src/assets DESTINATION ${CMAKE_BINARY_DIR})


execute_process(COMMAND "3D-CITY" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})