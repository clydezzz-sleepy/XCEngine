// XCENGINE
// XCGL.cpp
// This file has everything that has to do with OpenGL/GLFW, including wrappers for OpenGL/GLFW functions used for the engine.
#include "headers/XCImports.h"

// This function initializes the necessary GLFW components.
void XCEngine::GL::InitGL() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

XCWindow XCEngine::GL::WindowCreate() {
    GLFWwindow* window = nullptr;
    int attempts = 0;
    const int max_attempts = 3;

    while (attempts < max_attempts) {
        window = glfwCreateWindow(1080, 720, "XCEngine Game Engine", nullptr, nullptr);
        if (!window) {
            std::cerr << "Window did not load correctly. Trying again (" << (attempts + 1) << "/" << max_attempts << ").\n\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            attempts++;
            continue;
        }
        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD. Trying again (" << (attempts + 1) << "/" << max_attempts << ").\n\n";
            glfwDestroyWindow(window);
            window = nullptr;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            attempts++;
            continue;
        }
        break;
    }

    if (attempts == max_attempts) {
        std::cerr << "Fatal error: Could not create window after " << max_attempts << " attempts. Exiting.\n";
        std::exit(EXIT_FAILURE);
    }

    return window;
}
