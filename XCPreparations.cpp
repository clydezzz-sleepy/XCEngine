// XCENGINE
// XCPreparations.cpp
// This file contains what needs to be run first before anything else.

#include "headers/XCImports.h"
using namespace XCEngine;

namespace XCEngine {
    // This checks whether the game has an instance available to launch, and will stop otherwise.
    int GetGameInstance(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            UI::DestroyUI();
            OnLoad::UnloadResources();
            isDestroyed = true;
            Kill();
            return XC_FAILED;
        }
        else {
            std::string line;
            std::getline(file, line);
            if (line.find("// XCENGINE") != std::string::npos) {
                return XC_SUCCESS;
            }
            else {
                std::cerr << "Failed to initialize main file (" << filePath << ").\n";
                UI::DestroyUI();
                OnLoad::UnloadResources();
                isDestroyed = true;
                Kill();
                return XC_FAILED;
            }
        }
    }
}