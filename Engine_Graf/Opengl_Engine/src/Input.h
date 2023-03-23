#ifndef INPUT_H
#define INPUT_H

#include "DDLExport.h"
#include "glm/glm.hpp"

class Input
{
protected:
	DllExport static bool IsKeyPressedImpl(int keycode);
	DllExport static bool IsMouseButtonPressedImpl(int button);

	DllExport static float GetMouseXImpl();
	DllExport static float GetMouseYImpl();
	DllExport static glm::vec2 getMousePositionImpl();

public:
	DllExport inline static bool getKeyPressed(int keycode) { return IsKeyPressedImpl(keycode); };

	DllExport inline static bool getMouseButtonPressed(int button) { return IsMouseButtonPressedImpl(button); };

	DllExport inline static float getMouseX() { return GetMouseXImpl(); };
	DllExport inline static float getMouseY() { return GetMouseYImpl(); };
	DllExport inline static glm::vec2 getMousePosition() { return getMousePositionImpl(); };
};

#endif