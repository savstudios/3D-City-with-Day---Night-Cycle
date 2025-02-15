#version 450 core

out vec4 FragColor;

in vec3 normal;
in vec3 fragPos;
in vec2 texCoords;

uniform vec3 lightPos;
uniform vec3 viewPos;

struct Material{
   vec3 ambient;
   sampler2D diffuse;
   sampler2D specular;
   float shininess;
};

struct Light{
   vec3 pos;

   vec3 ambient;
   vec3 diffuse;
   vec3 specular;

   float constant;
   float linear;
   float quadratic;
};

uniform Material material;
uniform Light light;

void main(){

   // ambient
   vec3 ambient = material.ambient * light.ambient * texture(material.diffuse, texCoords).rgb;

   // diffuse
   vec3 norm = normalize(normal);
   vec3 lightDir = normalize(lightPos - fragPos);
   float diff = max(dot(norm, lightDir), 0.0f);

   vec3 diffuse = light.diffuse * (diff * texture(material.diffuse, texCoords).rgb);

   // specular
   vec3 viewDir = normalize(viewPos - fragPos);
   vec3 reflectDir = reflect(-lightDir, norm);
   float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);

   vec3 specular = light.specular * spec * texture(material.specular, texCoords).rgb;

   float distance = length(light.pos - fragPos);
   float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

   vec3 result = (ambient + diffuse + specular) * attenuation;

   FragColor = vec4(result, 1.0f);
};