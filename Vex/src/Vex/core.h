#pragma once

#include <memory>

#ifdef VX_PLATFORM_WINDOWS
	#if VX_DYNAMIC_LINK
		#ifdef VX_BUILD_DLL
			#define VEX_API _declspec(dllexport)
		#else
			#define VEX_API _declspec(dllimport)
		#endif
	#else
		#define VEX_API
	
	#endif
#else
	#error Vex only support Windows!
#endif

#ifdef VX_DEBUG
	#define VX_ENABLE_ASSERTS
#endif

#ifdef VX_ENABLE_ASSERTS
	#define VX_ASSERT(x, ...) { if(!(x)) {VX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define VX_CORE_ASSERT(x, ...) { if(!(x)) { VX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define VX_ASSERT(x, ...)
	#define VX_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)


#define VX_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)


namespace Vex {
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
}