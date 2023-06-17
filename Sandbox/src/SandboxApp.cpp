#include <Vex.h>

#include "imgui/imgui.h"

class ExampleLayer : public Vex::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Vex::Input::IsKeyPressed(VX_KEY_TAB))
			VX_CLIENT_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
	}

	void OnEvent(Vex::Event& event) override
	{
		if (event.GetEventType() == Vex::EventType::KeyPressed)
		{
			Vex::KeyPressedEvent& e = (Vex::KeyPressedEvent&)event;
			if (e.GetKeyCode() == VX_KEY_TAB)
				VX_CLIENT_TRACE("Tab key is pressed (event)!");
			VX_CLIENT_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Vex::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Vex::Application* Vex::CreateApplication()
{
	return new Sandbox();
}