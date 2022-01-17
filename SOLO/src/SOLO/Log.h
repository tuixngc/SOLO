#pragma once

#include <memory>
#include "core.h"

#include "spdlog\spdlog.h"


namespace SOLO {

	class SOLO_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

#define SOLO_CORE_ERROR(...)	::SOLO::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SOLO_CORE_WARN(...)		::SOLO::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SOLO_CORE_INFO(...)		::SOLO::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SOLO_CORE_TRACE(...)	::SOLO::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define SOLO_ERROR(...)			::SOLO::Log::GetClientLogger()->error(__VA_ARGS__)
#define SOLO_WARN(...)			::SOLO::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SOLO_INFO(...)			::SOLO::Log::GetClientLogger()->info(__VA_ARGS__)
#define SOLO_TRACE(...)			::SOLO::Log::GetClientLogger()->trace(__VA_ARGS__)
