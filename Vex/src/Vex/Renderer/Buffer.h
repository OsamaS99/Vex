#pragma once


namespace Vex
{

	enum class ShaderDataType {
		None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
	};

	static uint32_t ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case Vex::ShaderDataType::Float:
			return 4;
			break;
		case Vex::ShaderDataType::Float2:
			return 4 * 2;
			break;
		case Vex::ShaderDataType::Float3:
			return 4 * 3;
			break;
		case Vex::ShaderDataType::Float4:
			return 4 * 4;
			break;
		case Vex::ShaderDataType::Mat3:
			return 4 * 3 * 3;
			break;
		case Vex::ShaderDataType::Mat4:
			return 4 * 4 * 4;
			break;
		case Vex::ShaderDataType::Int:
			return 4;
			break;
		case Vex::ShaderDataType::Int2:
			return 4 * 2;
			break;
		case Vex::ShaderDataType::Int3:
			return 4 * 3;
			break;
		case Vex::ShaderDataType::Int4:
			return 4 * 4;
			break;
		case Vex::ShaderDataType::Bool:
			return 1;
			break;
		}

		VX_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	struct BufferElement
	{
		std::string Name;
		ShaderDataType Type;
		uint32_t Size;
		uint32_t Offset;
		bool Normalized;

		BufferElement() {};

		BufferElement(ShaderDataType type, const std::string& name, bool normalized = false) :
			Name(name), Type(type), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized) {

		}

		uint32_t GetComponentCount() const
		{
			switch (Type)
			{
			case Vex::ShaderDataType::Float:
				return 1;
				break;
			case Vex::ShaderDataType::Float2:
				return 2;
				break;
			case Vex::ShaderDataType::Float3:
				return 3;
				break;
			case Vex::ShaderDataType::Float4:
				return 4;
				break;
			case Vex::ShaderDataType::Mat3:
				return 3 * 3;
				break;
			case Vex::ShaderDataType::Mat4:
				return 4 * 4;
				break;
			case Vex::ShaderDataType::Int:
				return 1;
				break;
			case Vex::ShaderDataType::Int2:
				return 2;
				break;
			case Vex::ShaderDataType::Int3:
				return 3;
				break;
			case Vex::ShaderDataType::Int4:
				return 4;
				break;
			case Vex::ShaderDataType::Bool:
				return 1;
				break;
			}
			VX_CORE_ASSERT(false, "Unknown ShaderDataType!");
			return 0;
		
		}
	};

	class BufferLayout {
	public:

		BufferLayout() {}
		BufferLayout(std::initializer_list<BufferElement> elements):
		m_Elements(elements)
		{
			CalculateOffsetAndStride();
			
		}
		inline const std::vector<BufferElement>& GetElements() const { return m_Elements; }
		inline uint32_t GetStride() const { return m_Stride;  }


		std::vector<BufferElement>::iterator begin() { return m_Elements.begin();  }
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }


	private:
		void CalculateOffsetAndStride() {
			uint32_t offset = 0;
			m_Stride = 0;
			for (auto& element : m_Elements)
			{
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}
	private:
		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride = 0;

	};



	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& GetLayout() const = 0;


		static VertexBuffer* Create(float* vertices, uint32_t size);

	};


	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual uint32_t GetCount() const = 0;

		static IndexBuffer* Create(uint32_t* indices, uint32_t count);
	};

}