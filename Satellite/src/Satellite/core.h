#pragma once

#ifdef SAT_PLATFORM_WINDOWS
	#ifdef SAT_BUILD_DLL
		#define SATELLITE_API __declspec(dllexport)
	#else
		#define SATELLITE_API __declspec(dllimport)
	#endif // HZ_BUILD_DLL
#else
	#error Sattelite doesn't support the current operating system.
#endif
#ifdef SAT_DEBUG
	#define SAT_ENABLE_ASSERTS
#endif
#ifdef SAT_ENABLE_ASSERTS
	#define SAT_ASSERT(x, ...) { if(!(x)) { SAT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SAT_CORE_ASSERT(x, ...) { if(!(x)) { SAT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SAT_ASSERT(x, ...) 
	#define SAT_CORE_ASSERT(x, ...)
#endif


// returns value where bit x = 1 and all others are 0.
#define BIT(x) (1 << x)
