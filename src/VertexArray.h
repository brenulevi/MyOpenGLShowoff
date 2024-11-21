#pragma once

#include <glad/glad.h>

#include "VertexBuffer.h"

class VertexArray
{
public:
	VertexArray();
	VertexArray(const VertexBuffer& vbo);
	~VertexArray();

	inline void Bind() { glBindVertexArray(_id); }
	inline void Unbind() { glBindVertexArray(0); }

	void AddBuffer(const VertexBuffer& vbo);

private:
	GLuint _id;
};