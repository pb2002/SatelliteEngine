#pragma once
#include "Satellite/core.h"
#include "Satellite/events/event.h"
#include "Satellite/window.h"

namespace Satellite {
	class SATELLITE_API Application {

	public:
		Application();
		virtual ~Application();

		void run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in client.
	Application* CreateApplication();
}


