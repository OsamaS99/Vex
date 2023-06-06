#pragma once

#ifdef VX_PLATFORM_WINDOWS
	#ifdef VX_BUILD_DLL
		#define VEX_API _declspec(dllexport)
	#else
		#define VEX_API _declspec(dllimport)
	#endif
#else
	#error Vex only support Windows!
#endif

#ifdef VX_ENABLE_ASSERTS
	#define VX_ASSERT(x, ...) { if(!(x)) {VX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define VX_CORE_ASSERT(x, ...) { if(!(x)) { VX_CORE_ERROR("Assertion Failed: {0}", __VA__ARGS__); __debugbreak();}}
#else
	#define VX_ASSERT(x, ...)
	#define VX_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)


#define VX_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)