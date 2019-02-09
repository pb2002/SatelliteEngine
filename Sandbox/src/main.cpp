#include <Satellite.h>

class ExampleLayer : public Satellite::Layer {
public:
	ExampleLayer() : Layer("Example") {}
	void onUpdate() override {
		SAT_INFO(__FUNCTION__);
	}
	void onEvent(Satellite::Event& e) override {
		SAT_TRACE("{0}",e);
	}
};
class Sandbox : public Satellite::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}
	void run() {
		
	}
};

Satellite::Application* Satellite::CreateApplication() {
	return new Sandbox();
}