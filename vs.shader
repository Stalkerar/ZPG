#version 440
layout(location=0) in vec3 vp;
layout(location = 1) in vec3 vn;
layout(location = 2) in vec2 uv;

out vec3 vs_position;
out vec3 vs_normal;
out vec2 uvc;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;


void main () {
    vs_position = vec4(modelMatrix * vec4(vp, 1.f)).xyz / vec4(modelMatrix * vec4(vp, 1.f)).w;
   
    vs_normal = mat3(modelMatrix) * vn;
    uvc = uv;

    gl_Position = projectionMatrix * viewMatrix * modelMatrix* vec4(vp,1.f);
};