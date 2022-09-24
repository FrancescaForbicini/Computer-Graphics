#version 450

//color of the vertex to output
layout(location = 0) out vec4 outColor;

//time variable passed to the Fragment Shader
layout(set = 0, binding = 1) uniform GlobalUniformBufferObject {
	float time;
} gubo;

void main() {
	//computation of the color in output using a function of the time
	outColor = vec4(cos(gubo.time*3.14), sin(gubo.time*3.14), 0.5*cos(gubo.time*3.14) + 0.5*sin(gubo.time*3.14), 1.0f);
}
