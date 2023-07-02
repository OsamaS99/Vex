#pragma once

#include "Core.h"

#include "Window.h"
#include "Vex/LayerStack.h"
#include "Vex/Events/Event.h"
#include "Vex/Events/ApplicationEvent.h"

#include "Vex/ImGui/ImGuiLayer.h"


#include "Vex/Renderer/Shader.h"
#include "Vex/Renderer/Buffer.h"
#include "Vex/Renderer/VertexArray.h"

namespace Vex {

	class VEX_API Application
	{
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
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		//unsigned int m_VertexArray, m_IndexBuffer;
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;

	private: 
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}