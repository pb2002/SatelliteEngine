#pragma once
#include "Satellite/core.h"

#include "Satellite/window.h"
#include "Satellite/layerStack.h"

#include "Satellite/events/event.h"
#include "Satellite/events/appEvent.h"



namespace Satellite {
	class SATELLITE_API Application {

	public:
		Application();
		virtual ~Application();

		void run(); // Application Entry

		void onEvent(Event& e); // Event Callback

		// Layers -----------------------
		void PushLayer(Layer* layer); 
		void PushOverlay(Layer* overlay);
		// ------------------------------
		inline static Application& get() { return *s_Instance; }
		inline Window& getWindow() { return *m_Window; }
	private:
		// Event dispatch functions ------------
		bool onWindowCLose(WindowCloseEvent &e);
		static Application* s_Instance;
		// -------------------------------------
	private:

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in client.
	Application* CreateApplication();
}


