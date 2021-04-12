#include "Application.h"

void Application::Initialize() {
	this->_window.Initialize();

	VEngine::Utilities::Log._logger->info("Application initialized");
}

void Application::Update() {
	VEngine::Utilities::Log._logger->info("Application updating");
	while (this->_window.isRunning()) {
		glfwPollEvents();
	}
}