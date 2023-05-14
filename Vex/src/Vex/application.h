#pragma once

#include "Vex/Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Vex {

	class VEX_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();

}


