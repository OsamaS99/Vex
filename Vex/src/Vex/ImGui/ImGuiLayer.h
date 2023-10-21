#pragma once

#include "Vex/Core/Layer.h"

#include "Vex/Events/ApplicationEvent.h"
#include "Vex/Events/KeyEvent.h"
#include "Vex/Events/MouseEvent.h"

namespace Vex {

	class VEX_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}