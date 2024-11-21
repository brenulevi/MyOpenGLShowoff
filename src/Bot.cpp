#include "Bot.h"
#include "Application.h"

Bot::Bot()
{
	transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	transform.scale = glm::vec3(botWidth, botHeight, 1.0f);

	mesh.AddVertex(-0.5f, -0.5f, 0.0f);		// BL
	mesh.AddVertex(-0.5f, 0.5f, 0.0f);		// TL
	mesh.AddVertex(0.5f, 0.5f, 0.0f);		// TR
	mesh.AddVertex(0.5f, -0.5f, 0.0f);		// BR

	mesh.AddTriangle(0, 1, 2);				// BL TL TR
	mesh.AddTriangle(2, 3, 0);				// TR BR BL

	material.color = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
}

Bot::~Bot()
{
}

void Bot::Update()
{
	int wndWidth = Application::Get()->GetWindow().GetWidth();
	int wndHeight = Application::Get()->GetWindow().GetHeight();
	transform.position = glm::vec3(wndWidth - (botWidth / 2.0f), (wndHeight / 2.0f) + (movementOffset * wndHeight), 0.0f);
}
