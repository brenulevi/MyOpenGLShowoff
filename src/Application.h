#pragma once

#include <memory>
#include <glm/gtc/matrix_transform.hpp>

#include "Window.h"
#include "Shader.h"
#include "Renderer.h"

class Application
{
public:
	Application();
	~Application();

	void Run();

	inline void Close() { _running = false; }
	void Resize(int width, int height);

	inline Window& GetWindow() const { return *_window; }

	static Application* Get() { return _instance; }

private:
	std::unique_ptr<Window> _window;
	std::unique_ptr<Shader> _shader;
	std::unique_ptr<Renderer> _renderer;

	glm::mat4 _ortho;

	bool _running;

	static Application* _instance;
};