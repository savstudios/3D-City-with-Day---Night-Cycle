#version 450 core

out vec4 FragColor;

in vec3 normal;
in vec3 fragPos;

uniform vec3 objColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

vec3 norm = normalize(normal);
vec3 lightDir = normalize(lightPos - fragPos);

float specularStrength = 0.5f;

void main(){
   float diff = max(dot(norm, lightDir), 0.0f);

   vec3 viewDir = normalize(viewPos - fragPos);
   vec3 reflectDir = reflect(-lightDir, norm);
   float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
   vec3 specular = specularStrength * spec * lightColor;
   vec3 diffuse = diff * lightColor;


   float ambientStrength = 0.1f;
   vec3 ambient = ambientStrength * lightColor;

   vec3 result = (ambient + diffuse + specular) * objColor;

   FragColor = vec4(result, 1.0f);
};