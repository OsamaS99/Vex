
#include <Vex.h>


class ExampleLayer : public Vex::Layer {
public:
	ExampleLayer() : Layer("Example") {

	}
	
	void OnUpdate() override {
		VX_CORE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Vex::Event& event) override {
		VX_CORE_TRACE("{0}", event);
	}
};


class Sandbox : public Vex::Application
{
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushLayer(new Vex::ImGuiLayer());
	}

	~Sandbox() {

	}

};

Vex::Application* Vex::CreateApplication() {
	return new Sandbox();
}