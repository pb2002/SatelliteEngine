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

// returns value where bit x = 1 and all others are 0.
#define BIT(x) (1 << x)
