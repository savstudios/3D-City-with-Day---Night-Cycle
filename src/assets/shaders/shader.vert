#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec3 normal;
out vec3 fragPos;
out vec2 texCoords;

uniform mat4 viewProjModel;
uniform mat4 model;

void main(){
   gl_Position = viewProjModel * vec4(aPos, 1.0f);
   fragPos = vec3(model * vec4(aPos, 1.0f));
   normal = mat3(transpose(inverse(model))) * aNormal;
   texCoords = aTexCoords;
};