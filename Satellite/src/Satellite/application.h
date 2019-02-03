#pragma once
#include "Satellite/core.h"

namespace Satellite {
	class SATELLITE_API Application {

	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be defined in client.
	Application* CreateApplication();
}


