#include "satpch.h"
#include "application.h"
#include "input.h"

#include <glad/glad.h>

namespace Satellite {


	Application* Application::s_Instance = nullptr;

	Application::Application() {
		
		SAT_CORE_ASSERT(!s_Instance, "Assertion Failed: Application already exists.");
		s_Instance = this;
		

		m_Window = std::unique_ptr<Window>(Window::create());
		m_Window->setEventCallback(SAT_BIND_EVENT_FN(Application::onEvent));		
	}
	Application::~Application() {}

	void Application::run() {


		SAT_CORE_TRACE("(at {0}) Starting window update loop.", __FUNCTION__);

		while (m_Running) {

			// Clear screen (cornflower blue [0.2,0.5,1.0])
			glClearColor(0.2f, 0.5f, 1.0f, 1.0f);
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
		dispatcher.dispatch<WindowCloseEvent>(SAT_BIND_EVENT_FN(Application::onWindowCLose));
		
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->onEvent(e);
			if (e.handled)
				break;
		}
	}
	void Application::PushLayer(Layer * layer) {
		m_LayerStack.pushLayer(layer);
		layer->onAttach();
	}
	void Application::PushOverlay(Layer * overlay) {
		m_LayerStack.pushOverlay(overlay);
		overlay->onAttach();
	}
	bool Application::onWindowCLose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}

