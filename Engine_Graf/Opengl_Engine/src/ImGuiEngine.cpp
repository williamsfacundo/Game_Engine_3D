#include "ImGuiEngine.h"

ImGuiEngine* ImGuiEngine::_imGuiEngine = NULL;

DllExport ImGuiEngine::ImGuiEngine()
{
	_traslation = glm::vec3();
	_rotation = glm::vec3();
	_scale = glm::vec3();

	ImGui::CreateContext();
		
	ImGui_ImplGlfwGL3_Init(Window::getWindow()->getNativeWindow(), true);
	
	ImGui::StyleColorsDark();
}

DllExport ImGuiEngine::~ImGuiEngine()
{
	ImGui_ImplGlfwGL3_Shutdown();

	ImGui::DestroyContext();
}

DllExport ImGuiEngine* ImGuiEngine::getImGuiEngine()
{
	if (_imGuiEngine == NULL)
	{
		_imGuiEngine = new ImGuiEngine();
	}

	return _imGuiEngine;
}

DllExport void ImGuiEngine::imGuiStartDraw()
{
	ImGui_ImplGlfwGL3_NewFrame();
}

DllExport void ImGuiEngine::imGuiDrawObject(Entity2d* entity2d, int index)
{
	_traslation = entity2d->getPosition();
	_rotation = entity2d->getRotation();
	_scale = entity2d->getScale();

	if (ImGui::CollapsingHeader("Entity" + index))
	{
		ImGui::SliderFloat2("Translation", &_traslation.x, 0.0f, static_cast<float>(Window::GetScreenWidth())); // Al nombre de los sliders si agregas + index se soluciona un problema con multiples entidades
		ImGui::DragFloat("Rotation", &_rotation.z, 1.0f, 0.0f, 360.0f);
		ImGui::DragFloat2("Scale", &_scale.x, 0.1f, 0.0f, 10.0f);
	}

	entity2d->setPosition(_traslation);
	entity2d->setRotation(_rotation);
	entity2d->setScale(_scale);
}

DllExport void ImGuiEngine::imGuiEndDraw()
{
	ImGui::Render();

	ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
}