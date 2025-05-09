// XCENGINE
// XCEngine.cpp
// This is the main file of the entire engine. This is the file that runs the engine in one.
#include "headers/XCImports.h"

int main() {
	XCEngine::GL::InitGL();
	int a = XCEngine::GetGameInstance("XCEngine.exe");
	if (a == XCEngine::XC_FAILED) {
		XCEngine::Kill();
	}
	XCEngine::GL::WindowCreate();

	XCEngine::Main::StartLoop();
	
}