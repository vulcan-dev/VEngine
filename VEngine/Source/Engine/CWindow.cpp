#include "CWindow.h"

namespace VEngine {
	CWindow::CWindow(const uint32_t& width, const uint32_t& height, const std::string& title) : _width(width), _height(height), _title(title) {}

	void CWindow::Initialize() {
		glewExperimental = GL_TRUE;
		if (!glfwInit()) {
			Utilities::Log._logger->critical("Failed to initialize GLFW");
			glfwTerminate();
		}

		glfwWindowHint(GLFW_SAMPLES, 16);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwSetErrorCallback(this->CALLBACK_GLFW_ERROR);
		this->_window.reset(glfwCreateWindow(this->_height, this->_height, this->_title.c_str(), nullptr, nullptr));
		if (this->_window == nullptr) {
			Utilities::Log._logger->critical("Failed to create window");
			glfwTerminate();
		}

		Utilities::Log._logger->info("Window initialized (width: {0}, height: {1}, title: {2})", this->_width, this->_height, this->_title);
	}

	CWindow::~CWindow() {}
}