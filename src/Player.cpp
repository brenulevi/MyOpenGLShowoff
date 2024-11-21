#include "Player.h"
#include "Application.h"
#include "Input.h"
#include <iostream>

Player::Player()
{
	mesh.AddVertex(-0.5f, -0.5f, 0.0f);		// BL
	mesh.AddVertex(-0.5f,  0.5f, 0.0f);		// TL
	mesh.AddVertex( 0.5f,  0.5f, 0.0f);		// TR
	mesh.AddVertex( 0.5f, -0.5f, 0.0f);		// BR

	mesh.AddTriangle(0, 1, 2);				// BL TL TR
	mesh.AddTriangle(2, 3, 0);				// TR BR BL

	material.color = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);

	int wndWidth = Application::Get()->GetWindow().GetWidth();
	int wndHeight = Application::Get()->GetWindow().GetHeight();
	transform.position = glm::vec3(playerWidth / 2.0f, (wndHeight / 2.0f), 0.0f);
}

Player::~Player()
{
}

void Player::Update()
{
	if (Input::GetKey(GLFW_KEY_ESCAPE))
	{
		Application::Get()->Close();
	}

	int wndHeight = Application::Get()->GetWindow().GetHeight();
	auto& time = Application::Get()->GetTime();

	float playerHeight = playerHeightRatio * wndHeight;
	transform.scale = glm::vec3(playerWidth, playerHeight, 0.0f);	// if window resize, update scale

	if (Input::GetKey('W'))
	{
		transform.position.y += playerSpeed * time.deltaTime;
	}
	if (Input::GetKey('S'))
	{
		transform.position.y -= playerSpeed * time.deltaTime;
	}

	if (transform.position.y >= (wndHeight - playerHeight / 2.0f))
	{
		transform.position.y = (wndHeight - playerHeight / 2.0f);
	}
	else if (transform.position.y <= playerHeight / 2.0f)
	{
		transform.position.y = playerHeight / 2.0f;
	}
}
