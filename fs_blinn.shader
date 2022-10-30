#version 440
in vec3 vs_position;
in vec3 vs_normal;

out vec4 frag_colour;


uniform vec3 posCamera; //POPTAT SE
uniform vec3 lightPosition;
uniform bool useBlinn;

void main() {



    //Ambient light
    float ambientStr = 0.1;
    vec3 ambient = ambientStr * vec3(0.1f, 0.1f, 0.1f);

    //Diffuse light
    vec3 posToLightDirVec = normalize(lightPosition - vs_position);
    vec3 diffuseColor = vec3(1.f, 1.f, 1.f);
    float diffuseStr = clamp(dot(posToLightDirVec, vs_normal), 0, 1);
    vec3 diffuse = diffuseColor * diffuseStr;

    //Spec
    float dotProd = 0.0;
  
    vec3 specularFinal = vec3(0, 0, 0);
    if (dot(posToLightDirVec, vs_normal) > 0)
    {
        vec3 posToViewDirVec = normalize(posCamera - vs_position); // cam pos
        vec3 lightVectorpos = normalize(vs_position - lightPosition);
        if (useBlinn)
        {

            vec3 halfDir = normalize(lightVectorpos + posToViewDirVec);
            dotProd = dot(vs_normal, halfDir);
        }
        else
        {
            vec3 reflectDirVec = normalize(reflect(lightVectorpos, normalize(vs_normal)));
            dotProd = dot(posToViewDirVec, reflectDirVec);
        }
        float specularConstant = pow(max(dotProd, 0.0), 35);
        specularFinal = vec3(1.f, 1.f, 1.f) * specularConstant;

    }
    


    vec3 result = (ambient + diffuse + specularFinal) * vec3(0.0f, 1.0f, 4.5f);
    frag_colour = vec4(result, 1.0);
}