#version 450

//world, view and projection matrix passed to the Vertex Shader via the UniformBufferObject
layout(set = 0, binding = 0) uniform UniformBufferObject {
	mat4 worldMat;
	mat4 viewMat;
	mat4 prjMat;
} ubo;

//position of the current vertex in consideration
layout(location = 0) in vec3 inPosition;

void main() {

	//computation of the clipping coordinates of the vertex
	gl_Position = ubo.prjMat * ubo.viewMat * ubo.worldMat * vec4(inPosition, 1.0);
}
