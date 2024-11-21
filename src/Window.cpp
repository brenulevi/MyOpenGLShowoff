#include "Window.h"
#include "Application.h"

Window::Window(int width, int height, const char* title)
	: _width{width}, _height{height}
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_ptr = glfwCreateWindow(width, height, title, 0, 0);

	glfwMakeContextCurrent(_ptr);

	glfwSetWindowUserPointer(_ptr, this);

	glfwSetWindowCloseCallback(_ptr, [](GLFWwindow* window) {
			Application::Get()->Close();
		}
	);

	glfwSetFramebufferSizeCallback(_ptr, [](GLFWwindow* window, int width, int height) {
			auto wnd = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

			wnd->_width = width;
			wnd->_height = height;

			Application::Get()->Resize(width, height);
		}
	);
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Update()
{
	glfwPollEvents();
}

void Window::Present()
{
	glfwSwapBuffers(_ptr);
}
