#include "Application.h"
#include <glad/glad.h>
#include <iostream>

#include "Shader.h"
#include "VertexBuffer.h"
#include "VertexArray.h"

Application* Application::_instance = nullptr;

Application::Application()
	: _running{true}
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
	Shader shader = Shader("shaders/shader.vert", "shaders/shader.frag");

	// Create a vertex buffer for a triangle
	VertexBuffer vbo = VertexBuffer();
	std::vector<Vertex> vertices = {
		{ 0.0f,  0.5f, 0.0f},		// top
		{-0.5f, -0.5f, 0.0f},		// left
		{ 0.5f, -0.5f, 0.0f}		// right
	};
	// Add data to buffer
	vbo.PushData(vertices);

	// Create vertex array object
	VertexArray vao = VertexArray();
	// Add VBO to Vertex Array
	vao.AddBuffer(vbo);

	// Game loop
	while (_running)
	{
		// Pool window messages (treat)
		_window->Update();

		// Clear window framebuffer
		glClear(GL_COLOR_BUFFER_BIT);

		// Render must be here
		shader.Bind();
		vao.Bind();
		glDrawArrays(GL_TRIANGLES, 0, vbo.GetVertexCount());

		// Present new framebuffer
		_window->Present();
	}
}
