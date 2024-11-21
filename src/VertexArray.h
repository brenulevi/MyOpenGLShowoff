#pragma once

#include <glad/glad.h>

#include "VertexBuffer.h"
#include "IndexBuffer.h"

class VertexArray
{
public:
	VertexArray();
	VertexArray(const VertexBuffer& vbo, const IndexBuffer& ebo);
	~VertexArray();

	inline void Bind() { glBindVertexArray(_id); }
	inline void Unbind() { glBindVertexArray(0); }

	void AddBuffer(const VertexBuffer& vbo, const IndexBuffer& ebo);

private:
	GLuint _id;
};