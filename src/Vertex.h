#pragma once

struct Vertex
{
	struct Position
	{
		float x, y, z;
	} position;

	Vertex(float x, float y, float z) : position{x, y, z} {}
};