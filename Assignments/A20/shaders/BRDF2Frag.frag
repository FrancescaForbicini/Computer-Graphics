#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
    vec3 lightDir;
    vec3 lightColor;
    vec3 eyePos;
} gubo;

layout(binding = 3) uniform sampler2D texel;

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

vec3 direct_light_dir(vec3 pos) {
    // Directional light direction
    return gubo.lightDir;
}

vec3 direct_light_color(vec3 pos) {
    // Directional light color
    return gubo.lightColor;
}

vec3 Blinn_Specular_BRDF(vec3 N, vec3 V, vec3 Cs, float gamma){
    // Parameters are:
    //
    // vec3 N : normal vector
    // vec3 V : view direction
    // vec3 Cs : specular color
    // float gamma : Blinn exponent

    vec3 fSpecular = Cs * pow(clamp(dot(N,normalize(gubo.lightDir+V)),0.0f,1.0f),gamma);
    return fSpecular;
}

vec3 AmbientLighting(vec3 la, vec3 ma){
    return la*ma;
}

void main() {
    vec3 Norm = normalize(fragNorm);
    vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);
    //Ambient color
    vec3 AmbCol = texture(texSampler, fragTexCoord).rgb;
    //Specular color
    vec3 SpecCol = texture(texel, fragTexCoord).rgb;
    //Specular power
    float gamma = texture(texel, fragTexCoord).a * 200.0f;

    vec3 LCol = direct_light_color(fragPos);
    vec3 LDir = direct_light_dir(fragPos);

    vec3 fSpecular = Blinn_Specular_BRDF(Norm, EyeDir, SpecCol, gamma);
    vec3 Lamb = AmbientLighting(gubo.lightColor, AmbCol);

    vec3 res = LCol * fSpecular + Lamb;

    outColor = vec4(res, 1.0f);
}
