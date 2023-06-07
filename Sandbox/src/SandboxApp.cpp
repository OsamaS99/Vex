
#include <Vex.h>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>


class ExampleLayer : public Vex::Layer {
public:
	ExampleLayer() : Layer("Example") {

	}
	
	void OnUpdate() override {
		VX_CORE_INFO("ExampleLayer::Update");

		if (Vex::Input::IsKeyPressed(VX_KEY_TAB))
			VX_CLIENT_INFO("Tab key is pressed");
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