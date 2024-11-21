#pragma once

#include <glad/glad.h>
#include <vector>

#include "Vertex.h"

class VertexBuffer
{
public:
	VertexBuffer();
	VertexBuffer(const std::vector<Vertex>& data);
	~VertexBuffer();

	inline void Bind() const { glBindBuffer(GL_ARRAY_BUFFER, _id); }
	inline void Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

	void PushData(const std::vector<Vertex>& data);

	inline int GetStride() const { return _stride; }
	inline int GetVertexCount() const { return _vertexCount; }

private:
	GLuint _id;
	int _stride;
	int _vertexCount;
};