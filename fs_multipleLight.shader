#version 440
#define MAX_LIGHTS 3


in vec3 vs_position;
in vec3 vs_normal;
in vec2 uvc;

out vec4 frag_colour;


struct Pointlight
{
    vec3 position;

    vec3 diffuse;
    vec3 ambient;
    vec3 specular;

    float constant;
    float linearv;
    float quadratic;
};

struct DirLight
{
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight
{
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;

    float constant;
    float linearv;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform sampler2D textureUnitID;

uniform vec3 posCamera;
uniform vec3 lightPosition;

uniform DirLight dirLight;
uniform Pointlight pointlights[MAX_LIGHTS];
uniform SpotLight spotLight;

vec3 CalcPointLight(Pointlight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main() {

    vec3 norm = normalize(vs_normal);
    vec3 viewDir = normalize(posCamera - vs_position);
    
    // Directional lighting
    vec3 result = CalcDirLight(dirLight, norm, viewDir);

  
    // Point lights
    
   for (int i = 0; i < MAX_LIGHTS; i++)
   {
       result += CalcPointLight(pointlights[i], norm, vs_position, viewDir);
   }
    

    // Spot light
    result += CalcSpotLight(spotLight, norm, vs_position, viewDir);

    //frag_colour = vec4(result, 1.0);
    frag_colour = texture(textureUnitID, uvc)* vec4(result, 1.0);

}

vec3 CalcPointLight(Pointlight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);

    //Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);

    //Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 35);

    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linearv * distance + light.quadratic * (distance * distance));

    // Combine results
    vec3 ambient = light.ambient * vec3(1.0f, 1.0f, 1.0f);
    vec3 diffuse = light.diffuse * diff * vec3(1.0f, 1.0f, 1.0f);
    vec3 specular = light.specular * spec * vec3(1.0f, 1.0f, 1.0f);


    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);

}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);

    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);

    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 35);

    // Combine results
    vec3 ambient = light.ambient * vec3(1.0f, 1.0f, 1.0f);
    vec3 diffuse = light.diffuse * diff * vec3(1.0f, 1.0f, 1.0f);
    vec3 specular = light.specular * spec * vec3(1.0f, 1.0f, 1.0f);

    return (ambient + diffuse + specular);
}

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);

    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);

    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 35);

    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linearv * distance + light.quadratic * (distance * distance));

    // Spotlight intensity
    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

    // Combine results
    vec3 ambient = light.ambient * vec3(1.0f, 1.0f, 1.0f);
    vec3 diffuse = light.diffuse * diff * vec3(1.0f, 1.0f, 1.0f);
    vec3 specular = light.specular * spec * vec3(1.0f, 1.0f, 1.0f);

    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;

    return (ambient + diffuse + specular);
}