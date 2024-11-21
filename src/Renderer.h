#pragma once

#include "Mesh.h"
#include "Transform.h"
#include "Material.h"
#include "Shader.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Render(Mesh& mesh, Transform& transform, Material& material, Shader& shader);
};