#pragma once

#include "core.h"

namespace Vex {

	class VEX_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}


