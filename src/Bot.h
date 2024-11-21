#pragma once

#include "Transform.h"
#include "Mesh.h"
#include "Material.h"

class Bot
{
public:
	Bot();
	~Bot();

	void Update();

public:
	Transform transform;
	Mesh mesh;
	Material material;

private:
	int botWidth = 25;
	int botHeight = 175;
	int movementOffset = 0;
};