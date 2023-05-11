#include "vxpch.h"
#include "Vex/Application.h"

#include "Vex/Events/ApplicationEvent.h"
#include "Vex/Log.h"


namespace Vex {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		VX_CLIENT_TRACE(e);
		while (true);
	}

}