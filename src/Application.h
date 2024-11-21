#pragma once

#include <memory>

#include "Window.h"

class Application
{
public:
	Application();
	~Application();

	void Run();

	inline void Close() { _running = false; }

	static Application* Get() { return _instance; }

private:
	std::unique_ptr<Window> _window;

	bool _running;

	static Application* _instance;

};