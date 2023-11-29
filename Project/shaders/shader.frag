#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(set = 0, binding = 0) uniform GlobalUniformBufferObject {
	mat4 view;
	mat4 proj;
	vec3 lightColor;
	vec3 lightPos;
	vec2 cinout;
	vec3 spotDirection;
	vec3 eyePos;
} gubo;

layout(set = 1, binding = 1) uniform sampler2D texSampler;

layout(location = 0) in vec3 fragViewDir;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;
layout(location = 3) in vec3 fragPos;

layout(location = 0) out vec4 outColor;



void main() {
	const vec3  diffColor = texture(texSampler, fragTexCoord).rgb;
	const vec3  specColor = vec3(1.0f, 1.0f, 1.0f);
	const float specPower = 1000.0f;
	
	vec3 N = normalize(fragNorm);
	vec3 L = normalize(gubo.lightPos-fragPos);
	vec3 R = -reflect(L, N);
	vec3 W = normalize(gubo.eyePos - fragPos);

	
	// Lambert diffuse
	vec3 diffuse  = diffColor * max(dot(L,N), 0.0f) ;
	// Phong specular
	vec3 specular = specColor * pow(max(dot(R,W), 0.0f), specPower);


	// Hemispheric ambient
	vec3 ambient  = (vec3(0.1f,0.1f, 0.1f) * (1.0f + N.y) + vec3(0.0f,0.0f, 0.1f) * (1.0f - N.y)) * diffColor;
	
	//Spot light
	vec3 result =   gubo.lightColor *
				    clamp((dot(L,gubo.spotDirection) - gubo.cinout.y)/(gubo.cinout.x - gubo.cinout.y), 0.0, 1.0) *
					(diffuse + specular + ambient);

	outColor = vec4(result,1.0f);
}