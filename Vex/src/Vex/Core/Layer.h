#pragma once

#include "Vex/Core/Core.h"
#include "Vex/Core/Timestep.h"
#include "Vex/Events/Event.h"

namespace Vex {

	class VEX_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Vex::Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName;  }

	protected:
		std::string m_DebugName;
	};

}