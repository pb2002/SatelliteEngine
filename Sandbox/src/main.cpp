#include <Satellite.h>


class Sandbox : public Satellite::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
	void run() {
		
	}
};

Satellite::Application* Satellite::CreateApplication() {
	return new Sandbox();
}