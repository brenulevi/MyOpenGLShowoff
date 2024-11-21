#include "Player.h"
#include "Application.h"
#include "Input.h"
#include <iostream>

Player::Player()
{
	transform.position = glm::vec3(12.5f, 300.0f, 0.0f);
	transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	transform.scale = glm::vec3(25.0f, 175.0f, 1.0f);

	mesh.AddVertex(-0.5f, -0.5f, 0.0f);		// BL
	mesh.AddVertex(-0.5f,  0.5f, 0.0f);		// TL
	mesh.AddVertex( 0.5f,  0.5f, 0.0f);		// TR
	mesh.AddVertex( 0.5f, -0.5f, 0.0f);		// BR

	mesh.AddTriangle(0, 1, 2);				// BL TL TR
	mesh.AddTriangle(2, 3, 0);				// TR BR BL

	material.color = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
}

Player::~Player()
{
}

void Player::Update()
{
	// TODO Time class and player movement

	int wndWidth = Application::Get()->GetWindow().GetWidth();
	int wndHeight = Application::Get()->GetWindow().GetHeight();
	transform.position = glm::vec3(playerWidth / 2.0f, (wndHeight / 2.0f) + (movementOffset * wndHeight), 0.0f);

	if (Input::GetKey('W'))
	{
		//transform.position.y += playerSpeed * Time::deltaTime;
	}
	if (Input::GetKey('S'))
	{
		//transform.position.y -= playerSpeed * Time::deltaTime;
	}
}
