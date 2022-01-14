#pragma once

#ifdef SOLO_PLATFORM_WINDOWS
	#ifdef SOLO_BUILD_DLL
		#define SOLO_API __declspec(dllexport)
	#else
		#define SOLO_API __declspec(dllimport)
	#endif
#else
	#error SOLO only runs on Windows!
#endif