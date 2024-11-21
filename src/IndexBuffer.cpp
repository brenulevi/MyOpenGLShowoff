#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
	: _indexCount{ 0 }
{
	glGenBuffers(1, &_id);
}

IndexBuffer::IndexBuffer(const std::vector<unsigned int>& indices)
	: _indexCount{ 0 }
{
	glGenBuffers(1, &_id);

	PushData(indices);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &_id);
}

void IndexBuffer::PushData(const std::vector<unsigned int>& indices)
{
	_indexCount = static_cast<int>(indices.size());

	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indexCount * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
	Unbind();
}
