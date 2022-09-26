#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
    vec3 lightDir;
    vec3 lightPos;
    vec3 lightColor;
    vec4 lightParams;
    vec3 eyePos;
} gubo;

layout(binding = 3) uniform sampler2D texel;

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

vec3 spot_light_dir(vec3 pos) {
    // Spot light direction
    return normalize(gubo.lightPos - pos);
}

vec3 spot_light_color(vec3 pos) {
    // Spot light color
    float base = gubo.lightParams.w/length(gubo.lightPos - pos);
    vec3 first = gubo.lightColor * pow(base, gubo.lightParams.z);
    float second = clamp((dot(normalize(gubo.lightPos - pos), gubo.lightDir) - gubo.lightParams.y)/(gubo.lightParams.x - gubo.lightParams.y), 0.0f, 1.0f);
    return first * second;
}

vec3 Lambert_Diffuse_BRDF(vec3 L, vec3 N, vec3 C) {
    // Lambert Diffuse BRDF model
    // in all BRDF parameters are:
    // vec3 L : light direction
    // vec3 N : normal vector
    // vec3 C : main color (diffuse color, or specular color)
    return C*max(dot(L, N), 0.0);
}

vec3 Phong_Specular_BRDF(vec3 L, vec3 N, vec3 V, vec3 C, float gamma)  {
    // Phong Specular BRDF model
    // additional parameter:
    // float gamma : exponent of the cosine term
    vec3 Rx = -reflect(L, N);
    return C * pow(clamp(dot(V, Rx), 0.0, 1.0), gamma);
}

void main() {
    vec3 Norm = normalize(fragNorm);
    vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);
    vec3 DifCol = texture(texSampler, fragTexCoord).rgb;
    vec3 SpecCol = texture(texel, fragTexCoord).rgb;
    float gamma = texture(texel, fragTexCoord).a * 200.0f;

    vec3 LCol = spot_light_color(fragPos);
    vec3 LDir = spot_light_dir(fragPos);
    vec3 fDiffuse = Lambert_Diffuse_BRDF(LDir, Norm, DifCol);
    vec3 fSpecular = Phong_Specular_BRDF(LDir, Norm, EyeDir, SpecCol, gamma);

    vec3 res = LCol * (fDiffuse + fSpecular);

    outColor = vec4(res, 1.0f);
}
