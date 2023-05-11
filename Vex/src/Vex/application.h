#pragma once

#include "Vex/Core.h"

namespace Vex {

	class VEX_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}


