// XCENGINE
// XCExecute.cpp
// This file is used for necessary utilities needed to make XCEngine function properly for execution.

#include "headers/XCImports.h"
using namespace XCEngine;

// This function quits/kills the current game instance. This may fail, or may succeed.
// Returns: XC_FAILED or XC_SUCCESS
int XCEngine::Kill(bool relaunch) noexcept {
    try {
        Mouse::BlockMovement();
        std::cout << "Please wait while we unload everything for you..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        OnLoad::UnloadResources();
        UI::DestroyUI();
        isDestroyed = true;

        if (relaunch) {
            std::cout << "Relaunching the engine..." << std::endl;
            return XCEngine::Run("XCEngine.exe"); // Return the result of Run().
        }
        else {
            std::cout << "Shutdown complete." << std::endl;
            return XC_SUCCESS;
        }
    }
    catch (...) {
        std::cerr << "An exception occurred while shutting down. Forcing shutdown." << std::endl;
        return XC_FAILED;
    }
}

// This runs a certain file. This will mostly get used for either the user's current files or game files.
int XCEngine::Run(const std::string& filePath, bool getTime) {
    try {
        std::cout << "Please wait while we open another instance for you..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        XCEngine::isLoaded = true;

        if (getTime) {
            auto startTime = std::chrono::high_resolution_clock::now();
            std::ifstream file(filePath);
            auto endTime = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

            if (!file.is_open()) {
                std::cerr << "File " << filePath << " didn't open correctly. Please try again." << std::endl;
                return XC_FAILED;
            }
            else {
                std::cout << "File took " << duration.count() << " milliseconds to open." << std::endl;
                return XC_SUCCESS;
            }
        }
        else {
            std::ifstream file(filePath);
            if (!file.is_open()) {
                std::cerr << "File could not be opened." << std::endl;
                return XC_FAILED;
            }
            else {
                std::cout << "File " << filePath << " loaded." << std::endl;
                return XC_SUCCESS;
            }
            
        }
    }
    catch (...) {
        std::cerr << "An exception occurred while opening the file " << filePath << ". Forcing shutdown." << std::endl;
        return XC_FAILED;
    }
}

// This organizes the main loop for everything.
void XCEngine::Main::StartLoop() {
    GLFWwindow* window = GL::WindowCreate();
    while (!glfwWindowShouldClose(window)) {
        UI::LoadStartUI();
        if (GLFW_KEY_ENTER == GLFW_PRESS) {
            ImGui::Text("Please wait while we load everything for you...");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            Attr::GetUIAttributes();
            UI::LoadUI();
            Render::ProcessResources();
            Attr::GetObjectAttributes();
            OnLoad::LoadResources();
            Render::RenderObjects();
            Camera::GetCamera();
            Camera::GetCameraPos(1080, 720);
            Render::RenderCamera();
            Mouse::ProcessMovement();
        }
        else if (GLFW_KEY_ESCAPE == GLFW_PRESS) {
            Kill();
        }
    }
}