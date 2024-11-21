#pragma once

#include "Transform.h"
#include "Mesh.h"
#include "Material.h"

class Player
{
public:
	Player();
	~Player();

	void Update();

public:
	Transform transform;
	Mesh mesh;
	Material material;

private:
	int playerWidth = 25;
	int playerHeight = 175;
	float movementOffset = 0.0f;
	float playerSpeed = 2.0f;
};