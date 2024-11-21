#pragma once

#include <glad/glad.h>
#include <vector>

class IndexBuffer
{
public:
	IndexBuffer();
	IndexBuffer(const std::vector<unsigned int>& indices);
	~IndexBuffer();

	inline void Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id); }
	inline void Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

	void PushData(const std::vector<unsigned int>& indices);

	inline int GetIndexCount() const { return _indexCount; }

private:
	GLuint _id;
	int _indexCount;
};