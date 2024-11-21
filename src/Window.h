#pragma once

#include <GLFW/glfw3.h>

class Window
{
public:
	Window(int width, int height, const char* title);
	~Window();

	void Update();
	void Present();

	inline GLFWwindow* GetPtr() const { return _ptr; }
	inline int GetWidth() const { return _width; }
	inline int GetHeight() const { return _height; }

private:
	GLFWwindow* _ptr;
	int _width;
	int _height;
};