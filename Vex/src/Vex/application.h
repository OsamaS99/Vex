#pragma once

#include "Vex/Core.h"

#include "Vex/Window.h"
#include "Vex/LayerStack.h"
#include "Vex/Events/Event.h"
#include "Vex/Events/ApplicationEvent.h"

namespace Vex {

	class VEX_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	Application* CreateApplication();

}


