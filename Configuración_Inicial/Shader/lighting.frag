#version 330 core

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light
{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 color;

uniform vec3 viewPos;
uniform Material material;
uniform Light light, light2;

uniform sampler2D texture_diffusse;

void main()
{
    // Ambient (Luz 1)
    vec3 ambient1 = light.ambient * material.diffuse;
    
    // Diffuse (Luz 1)
    vec3 norm = normalize(Normal);
    vec3 lightDir1 = normalize(light.position - FragPos);
    float diff1 = max(dot(norm, lightDir1), 0.0);
    vec3 diffuse1 = light.diffuse * diff1 * material.diffuse;
    
    // Specular (Luz 1)
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir1 = reflect(-lightDir1, norm);
    float spec1 = pow(max(dot(viewDir, reflectDir1), 0.0), material.shininess);
    vec3 specular1 = light.specular * (spec1 * material.specular);

    // Cálculo de la luz 2 (Agregada)
    vec3 ambient2 = light2.ambient * material.diffuse;
    vec3 lightDir2 = normalize(light2.position - FragPos);
    float diff2 = max(dot(norm, lightDir2), 0.0);
    vec3 diffuse2 = light2.diffuse * diff2 * material.diffuse;
    vec3 reflectDir2 = reflect(-lightDir2, norm);
    float spec2 = pow(max(dot(viewDir, reflectDir2), 0.0), material.shininess);
    vec3 specular2 = light2.specular * (spec2 * material.specular);

    // Sumar los resultados de ambas luces
   // vec3 result = ambient1 + diffuse1 + specular1;
    vec3 result = ambient1 + diffuse1 + specular1 + ambient2 + diffuse2 + specular2;

    // Aplicar la textura
    color = vec4(result, 1.0f) * texture(texture_diffusse, TexCoords);
}
