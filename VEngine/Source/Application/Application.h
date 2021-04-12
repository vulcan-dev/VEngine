#pragma once

#include "../Engine/CWindow.h"

class Application {
public:
	void Initialize();
	void Update();
	void Render();

private:
	static constexpr uint32_t windowWidth = 1280;
	static constexpr uint32_t windowHeight = 1280;

	VEngine::CWindow _window { windowWidth, windowHeight, "Application" };
};