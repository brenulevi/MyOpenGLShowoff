#version 330 core

out vec4 aColor;

uniform vec4 uColor;

void main()
{
	aColor = uColor;
}