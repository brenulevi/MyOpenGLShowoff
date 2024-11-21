#include "Application.h"
#include <glad/glad.h>
#include <iostream>

Application* Application::_instance = nullptr;

Application::Application()
	: _running{ true }, _ortho{ 1.0f }
{
	if (_instance)
	{
		std::cout << "Application already running" << std::endl;
		return;
	}

	_instance = this;
}

Application::~Application()
{
}

void Application::Run()
{
	// Create application window
	_window = std::make_unique<Window>(800, 600, "My Window");

	// Load OpenGL functions
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize glad" << std::endl;
		return;
	}

	// Create simple shader
	_shader = std::make_unique<Shader>("shaders/shader.vert", "shaders/shader.frag");

	// Initiate renderer
	_renderer = std::make_unique<Renderer>();

	// Initiate time class
	_time = std::make_unique<Time>();

	// Initiate projection matrix
	_ortho = glm::ortho(0.0f, static_cast<float>(_window->GetWidth()), 0.0f, static_cast<float>(_window->GetHeight()), -1.0f, 1.0f);
	_shader->SetUniform("uProj", _ortho);

	// Create Player
	_player = std::make_unique<Player>();

	// Create Ball
	_ball = std::make_unique<Ball>();

	// Create Bot
	_bot = std::make_unique<Bot>();

	// Game loop
	while (_running)
	{
		// Pool window messages (treat)
		_window->Update();

		// Update deltatime
		_time->Update();

		// Update game objects
		_player->Update();
		_ball->Update();
		_bot->Update();

		// Check if ball collides with anything
		CheckCollisions();

		// Clear window framebuffer
		glClear(GL_COLOR_BUFFER_BIT);

		// Render must be here
		_renderer->Render(_player->mesh, _player->transform, _player->material, *_shader, GL_TRIANGLES);
		_renderer->Render(_ball->mesh, _ball->transform, _ball->material, *_shader, GL_TRIANGLES);
		_renderer->Render(_bot->mesh, _bot->transform, _bot->material, *_shader, GL_TRIANGLES);

		// Present new framebuffer
		_window->Present();
	}
}

void Application::Resize(int width, int height)
{
	glViewport(0, 0, width, height);
	_ortho = glm::ortho(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height), -1.0f, 1.0f);
	_shader->SetUniform("uProj", _ortho);
}

void Application::CheckCollisions()
{
}
