#include "vxpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Vex {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None: VX_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");  return nullptr;
			case RendererAPI::OpenGL: return new OpenGLVertexArray();

		}
		VX_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


}