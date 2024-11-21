#pragma once

#include <glad/glad.h>
#include <vector>

#include "Vertex.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Mesh
{
public:
	Mesh();
	~Mesh();

	inline void AddVertex(float x, float y, float z) { _vertices.push_back({ x, y, z }); _isVBODirt = true; }
	inline void AddTriangle(unsigned int t1, unsigned int t2, unsigned int t3) { _indices.push_back(t1); _indices.push_back(t2); _indices.push_back(t3); _isEBODirt = true; }

	void SetupDraw();
	inline void RemoveDraw() { _vao.Unbind(); }

	inline int GetIndexCount() const { return _ebo.GetIndexCount(); }

private:
	std::vector<Vertex> _vertices;
	std::vector<unsigned int> _indices;

	VertexArray _vao;
	VertexBuffer _vbo;
	IndexBuffer _ebo;

	bool _isVBODirt;
	bool _isEBODirt;
};