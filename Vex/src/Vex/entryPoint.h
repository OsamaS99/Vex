#pragma once

#ifdef VX_PLATFORM_WINDOWS

extern Vex::Application* Vex::CreateApplication();

int main(int argc, char** argv) {

	Vex::Log::Init();
	VX_CORE_WARN("Vex Initialized");
	VX_CLIENT_INFO("Hello Vex Engine!");

	auto app = Vex::CreateApplication();


	app->Run();
	delete app;
	return 0;
}

#else
#error Vex only support Windows!
#endif