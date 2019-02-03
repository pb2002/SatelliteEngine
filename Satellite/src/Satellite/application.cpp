#include "satpch.h"

#include "application.h"

#include "log.h"
#include "events\appEvent.h"

namespace Satellite {
	Application::Application() {}
	Application::~Application() {}

	void Application::run() {
		Satellite::Log::init();
		SAT_CORE_INFO("Greetings from Core Logger!");
		SAT_CORE_INFO("Verifying logger..");
		SAT_CORE_INFO("info format [green on black]");
		SAT_CORE_WARN("warning format [yellow on black]");
		SAT_CORE_ERROR("error format [red on black]");
		SAT_CORE_CRIT("critical format [white on red]");
		SAT_CORE_TRACE("trace format [white on black]");
		SAT_INFO("Greetings from Client Logger!");

		Satellite::WindowResizeEvent e(1280, 720);
		SAT_TRACE(e);
		while (true);
	}
}

