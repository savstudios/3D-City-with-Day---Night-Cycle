#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

out vec3 ourColor;
out vec2 texCoords;

uniform mat4 viewProjModel;

void main(){
   gl_Position = viewProjModel * vec4(aPos, 1.0f);
   ourColor = aColor;
   texCoords = aTex;
};