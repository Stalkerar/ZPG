#version 440
in vec3 vs_position;
in vec3 vs_normal;

out vec4 frag_colour;



uniform vec3 lightPosition;

void main() {

    //Ambient light
    float ambientStr = 0.1;
    vec3 ambient = ambientStr * vec3(0.1f, 0.1f, 0.1f);

    //Diffuse light
    vec3 posToLightDirVec = normalize(lightPosition - vs_position);
    vec3 diffuseColor = vec3(1.f, 1.f, 1.f);
    float diffuseStr = clamp(dot(posToLightDirVec, vs_normal), 0, 1);
    vec3 diffuse = diffuseColor * diffuseStr;

   



    vec3 result = (ambient + diffuse ) * vec3(0.0f, 1.0f, 4.5f);
    frag_colour = vec4(result, 1.0);
}