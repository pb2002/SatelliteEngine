#include "satpch.h"

#include "application.h"

#include <glad/glad.h>

#define BIND_EVENT_FN(x) std::bind(&x, this,std::placeholders::_1)
namespace Satellite {
	Application::Application() {
		Satellite::Log::init();

		m_Window = std::unique_ptr<Window>(Window::create());
		m_Window->setEventCallback(BIND_EVENT_FN(Application::onEvent));

	}
	Application::~Application() {}

	void Application::run() {


		SAT_CORE_TRACE("(at {0}) Starting window update loop.", __FUNCTION__);

		while (m_Running) {

			// Clear screen (cornflower blue [0.2,0.5,1.0])
			glClearColor(0.2, 0.5, 1.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			// Update layers ----------------
			for (Layer* layer : m_LayerStack)
				layer->onUpdate();			
			// ------------------------------

			// Update window
			m_Window->onUpdate();
		}
	}

	

	void Application::onEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowCLose));
		
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

