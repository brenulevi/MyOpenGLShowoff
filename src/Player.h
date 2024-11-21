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
	int playerWidth = 25;			// width of player collider and mesh
	float playerHeightRatio = 0.25;		// percentage of screen height
	float playerSpeed = 255.0f;		// player movement speed
};