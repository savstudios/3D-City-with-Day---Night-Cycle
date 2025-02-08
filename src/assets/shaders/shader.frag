#version 450 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 texCoords;

uniform sampler2D ourTex;

void main(){
   FragColor = texture(ourTex, texCoords) * vec4(ourColor, 1.0f);
};