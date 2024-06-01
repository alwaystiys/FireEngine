#pragma once

#ifdef FIRE_ENGINE_WINDOWS
	#ifdef FIRE_BUILD_DLL	
		#define FIRE_API __declspec(dllexport)
	#else
		#define FIRE_API __declspec(dllimport)
	#endif // FIRE_BUILD_DLL
#else
	#error Fire Engine only support Windows
#endif // FIRE_ENGINE_WINDOWS
