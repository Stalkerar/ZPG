#version 440
layout(location=0) in vec3 vp;
layout(location = 1) in vec3 vn;

out vec3 vs_position;
out vec3 vs_normal;


uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;


void main () {
    vs_position = vec4(modelMatrix * vec4(vp, 1.f)).xyz;
   
    vs_normal = mat3(modelMatrix) * vn;

    gl_Position = projectionMatrix * viewMatrix * modelMatrix* vec4(vp,1.f);
};