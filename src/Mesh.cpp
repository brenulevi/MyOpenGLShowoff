#include "Mesh.h"

Mesh::Mesh()
	: _isVBODirt{true}, _isEBODirt{true}
{
	_vao.AddBuffer(_vbo, _ebo);
}

Mesh::~Mesh()
{
}

void Mesh::SetupDraw()
{
	if (_isVBODirt)
	{
		_vbo.PushData(_vertices);

		_isVBODirt = false;
	}

	if (_isEBODirt)
	{
		_ebo.PushData(_indices);

		_isEBODirt = false;
	}

	_vao.Bind();
}
