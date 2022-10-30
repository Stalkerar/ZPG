#version 440
in vec3 vs_position;
in vec3 vs_normal;

out vec4 frag_colour;


uniform vec3 posCamera; //POPTAT SE
uniform vec3 lightPosition;

void main() {

	

	float ambientStr = 0.1;
	vec3 ambient = ambientStr * vec3(0.1f, 0.1f, 0.1f);

	frag_colour = vec4(0.385, 0.647, 0.812, 1.0) + vec4(ambient,1.0);
}
