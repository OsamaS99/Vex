#pragma once

#include "Vex/Renderer/Shader.h"

namespace Vex
{

	class OpenGLShader: public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;


		void UploadUniformInt(const std::string& name, const int& value);
		void UploadUniformFloat(const std::string& name, const float& value);
		void UploadUniformFloat2(const std::string& name, const glm::vec2& value);
		void UploadUniformFloat3(const std::string& name, const glm::vec3& value);
		void UploadUniformFloat4(const std::string& name, const glm::vec4& value);
		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
		void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);


	private:
		uint32_t m_RendererID;
	};

}