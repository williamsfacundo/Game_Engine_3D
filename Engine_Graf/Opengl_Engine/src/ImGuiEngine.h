#ifndef IM_GUI_ENGINE_H
#define IM_GUI_ENGINE_H

#include <glm/glm.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw_gl3.h>

#include "Entity2d.h"
#include "Window.h"

class ImGuiEngine
{
private:	
	static ImGuiEngine* _imGuiEngine;
	
	glm::vec3 _traslation;
	glm::vec3 _rotation;
	glm::vec3 _scale;

	DllExport ImGuiEngine();

public:
	DllExport ~ImGuiEngine();

	DllExport static ImGuiEngine* getImGuiEngine();

	DllExport void imGuiStartDraw();
	
	DllExport void imGuiDrawObject(Entity2d* entity2d, int index);
	
	DllExport void imGuiEndDraw();
};

#endif