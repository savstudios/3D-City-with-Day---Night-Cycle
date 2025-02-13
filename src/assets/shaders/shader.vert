#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 normal;
out vec3 fragPos;

uniform mat4 viewProjModel;
uniform mat4 model;

void main(){
   gl_Position = viewProjModel * vec4(aPos, 1.0f);
   fragPos = vec3(model * vec4(aPos, 1.0f));
   normal = mat3(transpose(inverse(model))) * aNormal;
   // texCoords = aTex;
};