#include "vxpch.h"
#include "OpenGLVertexArray.h"


#include<glad/glad.h>

namespace Vex
{

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type) {
		switch (type)
		{
		case Vex::ShaderDataType::Float: return GL_FLOAT;
		case Vex::ShaderDataType::Float2:return GL_FLOAT;
		case Vex::ShaderDataType::Float3: return GL_FLOAT;
		case Vex::ShaderDataType::Float4: return GL_FLOAT;
		case Vex::ShaderDataType::Mat3: return GL_FLOAT;
		case Vex::ShaderDataType::Mat4: return GL_FLOAT;
		case Vex::ShaderDataType::Int:return GL_INT;
		case Vex::ShaderDataType::Int2: return GL_INT;
		case Vex::ShaderDataType::Int3: return GL_INT;
		case Vex::ShaderDataType::Int4: return GL_INT;
		case Vex::ShaderDataType::Bool: return GL_BOOL;
		}
		VX_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;

	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	void  OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{
		VX_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout) {
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;

	}

}
