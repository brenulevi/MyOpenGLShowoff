#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &_id);
}

VertexArray::VertexArray(const VertexBuffer& vbo)
{
	glGenVertexArrays(1, &_id);

	AddBuffer(vbo);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &_id);
}

void VertexArray::AddBuffer(const VertexBuffer& vbo)
{
	Bind();
	vbo.Bind();

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vbo.GetStride(), (void*)(0 * sizeof(float)));
	glEnableVertexAttribArray(0);

	Unbind();
	vbo.Unbind();
}
