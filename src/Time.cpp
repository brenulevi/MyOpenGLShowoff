#include "Time.h"
#include <GLFW/glfw3.h>

Time::Time()
	: deltaTime{0.0f}, _lastTime{0.0}
{
}

Time::~Time()
{
}

void Time::Update()
{
	float currentTime = glfwGetTime();
	deltaTime = currentTime - _lastTime;
	_lastTime = currentTime;
}
