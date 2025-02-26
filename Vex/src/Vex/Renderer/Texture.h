#pragma once

#include <string>
#include "Vex/Core/core.h"


namespace Vex {

	class Texture {
	public:
		
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void Bind(uint32_t slot) const = 0;

	};

	class Texture2D : public Texture
	{
	public:
		static Ref<Texture2D> Create(const std::string& path);

	};
}