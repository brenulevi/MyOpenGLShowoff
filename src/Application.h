#pragma once

#include <memory>
#include <glm/gtc/matrix_transform.hpp>

#include "Window.h"
#include "Shader.h"
#include "Renderer.h"
#include "Time.h"
#include "Player.h"
#include "Ball.h"
#include "Bot.h"

class Application
{
public:
	Application();
	~Application();

	void Run();

	inline void Close() { _running = false; }
	void Resize(int width, int height);

	inline Window& GetWindow() const { return *_window; }
	inline Time& GetTime() const { return *_time; }

	static Application* Get() { return _instance; }

private:
	void CheckCollisions();

private:
	std::unique_ptr<Window> _window;
	std::unique_ptr<Shader> _shader;
	std::unique_ptr<Renderer> _renderer;
	std::unique_ptr<Time> _time;

	std::unique_ptr<Player> _player;
	std::unique_ptr<Ball> _ball;
	std::unique_ptr<Bot> _bot;

	glm::mat4 _ortho;

	bool _running;

	static Application* _instance;
};