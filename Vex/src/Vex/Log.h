#pragma once

#include "Vex/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Vex {
	class VEX_API Log {

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	
	};

}

#define VX_CORE_ERROR(...)    ::Vex::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VX_CORE_WARN(...)     ::Vex::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VX_CORE_INFO(...)     ::Vex::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VX_CORE_TRACE(...)    ::Vex::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define VX_CLIENT_ERROR(...)  ::Vex::Log::GetClientLogger()->error(__VA_ARGS__)
#define VX_CLIENT_WARN(...)   ::Vex::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VX_CLIENT_INFO(...)   ::Vex::Log::GetClientLogger()->info(__VA_ARGS__)
#define VX_CLIENT_TRACE(...)  ::Vex::Log::GetClientLogger()->trace(__VA_ARGS__)




