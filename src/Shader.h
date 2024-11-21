#pragma once

#include <glad/glad.h>

class Shader
{
public:
	Shader(const char* vert, const char* frag);
	~Shader();

	void Bind();
	void Unbind();

	void SetUniform(const char* name, int value);

private:
	GLuint CreateShader(GLenum type, const char* path);

private:
	GLint _id;
};
