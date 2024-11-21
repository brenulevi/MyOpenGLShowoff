#pragma once

#include "Transform.h"
#include "Mesh.h"
#include "Material.h"

class Ball
{
public:
	Ball();
	~Ball();

	void Update();

public:
	Transform transform;
	Mesh mesh;
	Material material;

private:
	float ballSize = 15.0f;
};