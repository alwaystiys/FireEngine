#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"


namespace FireEngine {
	class FIRE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//Core log macros 
#define FIRE_CORE_TRACE(...)	::FireEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FIRE_CORE_INFO(...)		::FireEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FIRE_CORE_WARN(...)		::FireEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FIRE_CORE_ERROR(...)	::FireEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FIRE_CORE_FATAL(...)	::FireEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros 
#define FIRE_TRACE(...)			::FireEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FIRE_INFO(...)			::FireEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define FIRE_WARN(...)			::FireEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FIRE_ERROR(...)			::FireEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define FIRE_FATAL(...)			::FireEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

// if dst build
//#define FIRE_INFO