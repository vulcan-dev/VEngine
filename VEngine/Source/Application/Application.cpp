#include "Application.h"

void Application::Initialize() {
	this->_window.Initialize();
	if (this->_window.getWindow() == nullptr) {
		VEngine::Utilities::Log._logger->critical("_window.getWindow() is nullptr");
		glfwTerminate();
	}

	glfwMakeContextCurrent(this->_window.getWindow());

	VEngine::Utilities::Log._logger->info("Application initialized");
}

void Application::Update() {
	VEngine::Utilities::Log._logger->info("Application updating");
	while (this->_window.isRunning()) {
		this->Render();

		glfwPollEvents();
	}
}

void Application::Render() {
	glClearColor(1.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glfwSwapBuffers(this->_window.getWindow());
}