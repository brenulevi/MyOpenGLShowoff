#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
	: _stride{ sizeof(Vertex) }, _vertexCount{0}
{
	glGenBuffers(1, &_id);
}

VertexBuffer::VertexBuffer(const std::vector<Vertex>& data)
	: _stride{ sizeof(Vertex) }, _vertexCount{0}
{
	glGenBuffers(1, &_id);

	PushData(data);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &_id);
}

void VertexBuffer::PushData(const std::vector<Vertex>& data)
{
	_vertexCount = static_cast<int>(data.size());

	Bind();
	glBufferData(GL_ARRAY_BUFFER, _vertexCount * _stride, data.data(), GL_STATIC_DRAW);
	Unbind();
}
