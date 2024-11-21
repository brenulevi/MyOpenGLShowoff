#include "Ball.h"
#include "Application.h"

Ball::Ball()
{
	auto& wnd = Application::Get()->GetWindow();
	transform.position = glm::vec3(wnd.GetWidth() / 2.0f, wnd.GetHeight() / 2.0f, 0.0f);

	mesh.AddVertex(-0.5f, -0.5f, 0.0f);		// BL
	mesh.AddVertex(-0.5f, 0.5f, 0.0f);		// TL
	mesh.AddVertex(0.5f, 0.5f, 0.0f);		// TR
	mesh.AddVertex(0.5f, -0.5f, 0.0f);		// BR

	mesh.AddTriangle(0, 1, 2);				// BL TL TR
	mesh.AddTriangle(2, 3, 0);				// TR BR BL

	material.color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	transform.scale = glm::vec3(ballSize, ballSize, 1.0f);
}

Ball::~Ball()
{
}

void Ball::Update()
{
}
