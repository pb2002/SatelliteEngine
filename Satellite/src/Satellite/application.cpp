#include "satpch.h"

#include "application.h"
#include <GLFW/glfw3.h>
#define BIND_EVENT_FN(x) std::bind(&x, this,std::placeholders::_1)
namespace Satellite {
	Application::Application() {
		Satellite::Log::init();
		SAT_CORE_WARN("(at {0}) Greetings from Core Logger! :D", __FUNCTION__);
		SAT_WARN("(at {0}) Greetings from Client Logger! :D", __FUNCTION__);

		SAT_CORE_TRACE("(at {0}) Creating main window:", __FUNCTION__);
		m_Window = std::unique_ptr<Window>(Window::create());
		m_Window->setEventCallback(BIND_EVENT_FN(Application::onEvent));

	}
	Application::~Application() {}

	void Application::run() {


		SAT_CORE_TRACE("(at {0}) Starting window update loop.", __FUNCTION__);

		while (m_Running) {
			glClearColor(0.2, 0.5, 1.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->onUpdate();
		}
	}

	

	void Application::onEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowCLose));

		SAT_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->onEvent(e);
			if (e.handled)
				break;
		}
	}
	void Application::PushLayer(Layer * layer) {
		m_LayerStack.pushLayer(layer);
	}
	void Application::PushOverlay(Layer * overlay) {
		m_LayerStack.pushOverlay(overlay);
	}
	bool Application::onWindowCLose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}

