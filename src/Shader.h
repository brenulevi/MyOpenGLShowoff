#pragma once

#include <glad/glad.h>
#include <unordered_map>
#include <string>
#include <glm/gtc/matrix_transform.hpp>

class Shader
{
public:
	Shader(const char* vert, const char* frag);
	~Shader();

	void Bind();
	void Unbind();

	void SetUniform(const char* name, const int value);
	void SetUniform(const char* name, const glm::vec4& value);
	void SetUniform(const char* name, const glm::mat4& value);

private:
	GLuint CreateShader(GLenum type, const char* path);
	GLint GetUniformLocation(const char* name);

private:
	GLint _id;
	std::unordered_map<std::string, GLint> _uniforms;
};
