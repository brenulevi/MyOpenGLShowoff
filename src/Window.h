#pragma once

#include <GLFW/glfw3.h>

class Window
{
public:
	Window(int width, int height, const char* title);
	~Window();

	void Update();
	void Present();

private:
	GLFWwindow* _ptr;
	int _width;
	int _height;
};