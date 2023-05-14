
#include <Vex.h>

class Sandbox : public Vex::Application
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

Vex::Application* Vex::CreateApplication() {
	return new Sandbox();
}