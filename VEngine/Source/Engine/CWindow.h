#pragma once

#include "Utilities.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>

namespace VEngine {
	struct sDestroyWindow {
		void operator()(GLFWwindow* ptr) {
			glfwDestroyWindow(ptr);
		}
	};

	class CWindow {
	public:
		CWindow(const uint32_t& width = 1280, const uint32_t& height = 960, const std::string& title = "Application");
		CWindow(const CWindow&) = delete;
		CWindow& operator=(const CWindow&) = delete;

		void Initialize();

		inline const bool isRunning() const { return !glfwWindowShouldClose(this->_window.get()); }

		~CWindow();

	private:
		static inline void CALLBACK_GLFW_ERROR(int error, const char* description) {
			Utilities::Log._logger->critical("CALLBACK_GLFW_ERROR Called : [{0}] - {1}", error, description);
		}

	private:
		typedef std::unique_ptr<GLFWwindow, sDestroyWindow> smart_GLFWwindow;

		smart_GLFWwindow _window;

		uint32_t _width, _height = 0;
		std::string _title = "";
	};
}