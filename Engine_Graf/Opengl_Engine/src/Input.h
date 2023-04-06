#ifndef INPUT_H
#define INPUT_H

#include <glm/glm.hpp>

#include "DDLExport.h"
#include "Window.h"

using namespace glm;

class Input
{
private:
	DllExport static bool IsKeyPressedImpl(int keycode);

	DllExport static bool IsMouseButtonPressedImpl(int button);

	DllExport static float GetMouseXImpl();
	DllExport static float GetMouseYImpl();

	DllExport static vec2 getMousePositionImpl();

public:
	DllExport static void hideCursor();

	DllExport static bool getKeyPressed(int keycode);

	DllExport static bool getMouseButtonPressed(int button);

	DllExport static float getMouseX();
	DllExport static float getMouseY();

	DllExport static vec2 getMousePosition();
};

#endif