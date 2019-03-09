#pragma once

#ifdef SAT_PLATFORM_WINDOWS

extern Satellite::Application* Satellite::CreateApplication();

int main(int argc, char** argv) {
	Satellite::Log::init();

	auto app = Satellite::CreateApplication();
	app->run();
	delete app;
}
#endif