// XCENGINE
// XCUI.cpp
// This file uses the UI used in the game engine. Dear ImgGUI will be used for this.

#include "../headers/XCImports.h"

void XCEngine::UI::LoadStartUI() {
	static int contextTimes = 0;
	IMGUI_CHECKVERSION();
	if (contextTimes == 0) {
		ImGui::CreateContext();
		contextTimes++;
	}
	XCUI_IO IO = ImGui::GetIO(); (void)IO;

	IO.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	IO.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

	ImGui::StyleColorsDark();

	ImGuiStyle& style = ImGui::GetStyle();
	if (IO.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
		style.WindowRounding = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

    XCWindow window = XCEngine::GL::WindowCreate();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330 core");

	ImGui::NewFrame();

	ImGui::Begin("XCEngine Game Engine");
	ImGui::Text("Welcome");
	ImGui::Button("Load File");
	ImGui::End();
}

void XCEngine::UI::LoadUI() {
	// ...
}

int XCEngine::UI::DestroyUI() {
	// ...

	return XC_NEUTRAL; // Must return a value right now, or else we'll get a compilation error.
}