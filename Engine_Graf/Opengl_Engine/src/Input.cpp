#include "Input.h"

DllExport bool Input::IsKeyPressedImpl(int keycode)
{
	auto state = glfwGetKey(Window::getWindow()->getGLFWwindow(), keycode);

	return (state == GLFW_PRESS || state == GLFW_REPEAT);
}

DllExport bool Input::IsMouseButtonPressedImpl(int button)
{
	auto state = glfwGetMouseButton(Window::getWindow()->getGLFWwindow(), button);

	return state == GLFW_PRESS;
}

DllExport float Input::GetMouseXImpl()
{
	vec2 position = getMousePositionImpl();
	return position.x;
}

DllExport float Input::GetMouseYImpl()
{
	vec2 position = getMousePositionImpl();
	return position.y;
}

DllExport vec2 Input::getMousePositionImpl()
{
	double xPos, yPos;
	Window* window = Window::getWindow();
	glfwGetCursorPos(window->getGLFWwindow(), &xPos, &yPos);

	return vec2((float)xPos, (float)yPos - window->getScreenHeight());
}

DllExport bool Input::getKeyPressed(int keycode) 
{
	return IsKeyPressedImpl(keycode); 
}

DllExport bool Input::getMouseButtonPressed(int button) 
{ 
	return IsMouseButtonPressedImpl(button); 
}

DllExport float Input::getMouseX()
{ 
	return GetMouseXImpl();
}

DllExport float Input::getMouseY() 
{ 
	return GetMouseYImpl(); 
}

DllExport vec2 Input::getMousePosition() 
{ 
	return getMousePositionImpl();
}