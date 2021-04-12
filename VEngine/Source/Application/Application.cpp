#include "Application.h"

void Application::Initialize() {
	// Initialize the window
	this->_window.Initialize();

	// Added this for testing but I'll keep it for now
	if (this->_window.getWindow() == nullptr) {
		VEngine::Utilities::Log._logger->critical("_window.getWindow() is nullptr. Closing application");
		glfwTerminate();
	}

	// Set the current context to this window
	glfwMakeContextCurrent(this->_window.getWindow());

	VEngine::Utilities::Log._logger->info("Application initialized");
}

void Application::Update() {
	VEngine::Utilities::Log._logger->info("Application updating");
	while (this->_window.isRunning()) {
		this->Render();

		glfwPollEvents(); // glfw handles the events so we need to call this function every update. if we press a key, close the window, etc.. this handles it
	}
}

void Application::Render() {
	glClearColor(.2f, .2f, .2f, 1.f); // set the background colour of the window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glfwSwapBuffers(this->_window.getWindow()); // swaps the buffers (as u can see)
}