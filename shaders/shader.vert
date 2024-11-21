#version 330 core

layout (location = 0) in vec3 aPos;

uniform mat4 uProj;
uniform mat4 uWorld;

void main()
{
	gl_Position = uProj * uWorld * vec4(aPos, 1.0f);
}