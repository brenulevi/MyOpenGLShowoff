#include "Input.h"
#include "Application.h"

bool Input::GetKey(int key)
{
    auto& wnd = Application::Get()->GetWindow();
    return (glfwGetKey(wnd.GetPtr(), key) == GLFW_PRESS);
}
