#include <Satellite.h>

class ExampleLayer : public Satellite::Layer {
public:
	ExampleLayer() : Layer("Example") {

	}
	void onUpdate() override {

	}
	void onEvent(Satellite::Event& e) override {

	}
};

class Sandbox : public Satellite::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Satellite::ImGuiLayer());
	}
	~Sandbox() {

	}
	void run() {

	}
};

Satellite::Application* Satellite::CreateApplication() {
	return new Sandbox();
}