#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Shader::Shader(const char* vert, const char* frag)
{
	GLuint vs = CreateShader(GL_VERTEX_SHADER, vert);
	if (!vs)
	{
		std::cout << "Failed to create and compile vertex shader" << std::endl;
		return;
	}

	GLuint fs = CreateShader(GL_FRAGMENT_SHADER, frag);

	if (!fs)
	{
		std::cout << "Failed to create and compile fragment shader" << std::endl;
		glDeleteShader(vs);
		return;
	}

	_id = glCreateProgram();
	glAttachShader(_id, vs);
	glAttachShader(_id, fs);
	glLinkProgram(_id);

	glDeleteShader(vs);
	glDeleteShader(fs);

	// Check program link result
	int result;
	glGetProgramiv(_id, GL_LINK_STATUS, &result);
	if (!result)
	{
		char err[128];
		glGetProgramInfoLog(_id, 128, 0, err);
		std::cout << err << std::endl;
		glDeleteProgram(_id);
	}
}

Shader::~Shader()
{
	glDeleteProgram(_id);
}

void Shader::Bind()
{
	glUseProgram(_id);
}

void Shader::Unbind()
{
	glUseProgram(0);
}

void Shader::SetUniform(const char* name, int value)
{
}

GLuint Shader::CreateShader(GLenum type, const char* path)
{
	GLuint shader = glCreateShader(type);

	std::fstream file(path);

	if (!file.is_open())
	{
		std::cout << "invalid shader path" << std::endl;
		glDeleteShader(shader);
		return 0;
	}
	
	std::stringstream ss;
	ss << file.rdbuf();
	std::string str = ss.str();
	const char* source = str.c_str();

	glShaderSource(shader, 1, &source, 0);
	glCompileShader(shader);

	// Check shader compile status
	int result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		char err[128];
		glGetShaderInfoLog(shader, 128, 0, err);
		std::cout << err << std::endl;
		glDeleteShader(shader);
		return 0;
	}

	return shader;
}
