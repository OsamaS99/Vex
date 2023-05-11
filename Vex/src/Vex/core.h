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

#define BIT(x) (1 << x)