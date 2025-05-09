// XCENGINE
// XCEngine.h
// This file contains all the XCEngine function declaration that will be used in other files.

#pragma once
#define XCWindow GLFWwindow*
#define XCUI_IO ImGuiIO&
#include "XCEngineImports.h" // Not Imports.h, as it `#include`s the XCEngine.h file itself, leading to a circular include.
 
namespace XCEngine { // Our main namespace.
	namespace Camera {
		void GetCamera(); // Gets the current camera.
		void GetCameraPos(unsigned int xPos, unsigned int yPos); // Gets the current camera position.
	}
	namespace OnLoad {
		void LoadResources(); // Loads resources.
		void UnloadResources(); // Unloads resources.
	}
	namespace Mouse {
		void ProcessMovement(); // Processes mouse movement.
		void BlockMovement(); // Blocks mouse movement.
	}
	namespace UI {
		void LoadStartUI(); // Loads the UI shown when you start the engine first.
		void LoadUI(); // Loads the real UI.
		int DestroyUI(); // Destroys (/unloads) the UI.
	}
	namespace Attr {
		void GetUIAttributes(); // Gets the attributes for the UI.
		void GetObjectAttributes(); // Gets attributes for render objects.
	}
	namespace Render {
		void RenderCamera(); // Renders the camera.
		void RenderObjects(); // Renders the objects.
		void ProcessResources(); // Processes object resources.
	}
	namespace GL {
		void InitGL(); // Initializes OpenGL/GLFW.
		GLFWwindow* WindowCreate(); // Initializes and creates a window instance.
	}
	namespace Main {
         void StartLoop(); // The main starting loop of the entire game engine.
	}
	int GetGameInstance(const std::string& filePath = "XCEngine.cpp"); // Gives information about the game instance, whether it exists or not.	inline bool isLoaded = false; // Tells whether the engine loaded or not.
	inline bool isDestroyed = false; // Tells whether the engine is destroyed (/killed) or not.
	inline bool isLoaded = false; // Tells whether the engine is loaded or not.
	constexpr int XC_SUCCESS = 1; // Indicates engine success (for instances, rendering, processing, destroying, etc.).
	constexpr int XC_NEUTRAL = 0; // A neutral integer to indicate that nothing too bad happened.
	constexpr int XC_FAILED = -1; // Indicates engine failure (for when the engine has failed for any kind of reason.).

	int Run(const std::string& filePath, bool getTime = false); // Runs the engine.
	int Kill(bool relaunch = false) noexcept; // Kills (closes) the game.
	
}
