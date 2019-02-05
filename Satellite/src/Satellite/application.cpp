#include "satpch.h"

#include "application.h"

#include "log.h"
#include "events\appEvent.h"

#include <GLFW/glfw3.h>

namespace Satellite {
	Application::Application() {
		Satellite::Log::init();
		SAT_CORE_WARN("Greetings from Core Logger! :D");
		SAT_WARN("Greetings from Client Logger! :D");

		SAT_CORE_TRACE("Creating main window:");
		m_Window = std::unique_ptr<Window>(Window::create());
	}
	Application::~Application() {}

	void Application::run() {
		

		SAT_CORE_TRACE("Starting window update loop.");

		while (m_Running) {
			glClearColor(0.2,0.5,1.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->onUpdate();
		}
	}
}

