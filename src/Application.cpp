#include "Application.h"
#include <glad/glad.h>
#include <iostream>

#include "Player.h"
#include "Bot.h"

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

	// Initiate projection matrix
	_ortho = glm::ortho(0.0f, static_cast<float>(_window->GetWidth()), static_cast<float>(_window->GetHeight()), 0.0f, -1.0f, 1.0f);
	_shader->SetUniform("uProj", _ortho);

	// Create Player
	Player player = Player();

	// Create Bot
	Bot bot = Bot();

	// Game loop
	while (_running)
	{
		// Pool window messages (treat)
		_window->Update();

		player.Update();
		bot.Update();

		// Clear window framebuffer
		glClear(GL_COLOR_BUFFER_BIT);

		// Render must be here
		_renderer->Render(player.mesh, player.transform, player.material, *_shader);
		_renderer->Render(bot.mesh, bot.transform, bot.material, *_shader);

		// Present new framebuffer
		_window->Present();
	}
}

void Application::Resize(int width, int height)
{
	glViewport(0, 0, width, height);
	_ortho = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);
	_shader->SetUniform("uProj", _ortho);
}
