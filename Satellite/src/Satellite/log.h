#pragma once
#include "satpch.h"

#include "Satellite/core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
namespace Satellite {
	class SATELLITE_API Log {
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
		
	private:		
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define SAT_CORE_CRIT(...) ::Satellite::Log::getCoreLogger()->critical(__VA_ARGS__)
#define SAT_CORE_ERROR(...) ::Satellite::Log::getCoreLogger()->error(__VA_ARGS__)
#define SAT_CORE_WARN(...) ::Satellite::Log::getCoreLogger()->warn(__VA_ARGS__)
#define SAT_CORE_INFO(...) ::Satellite::Log::getCoreLogger()->info(__VA_ARGS__)
#define SAT_CORE_TRACE(...) ::Satellite::Log::getCoreLogger()->trace(__VA_ARGS__)

#define SAT_CRIT(...) ::Satellite::Log::getClientLogger()->critical(__VA_ARGS__)
#define SAT_ERROR(...) ::Satellite::Log::getClientLogger()->error(__VA_ARGS__)
#define SAT_WARN(...) ::Satellite::Log::getClientLogger()->warn(__VA_ARGS__)
#define SAT_INFO(...) ::Satellite::Log::getClientLogger()->info(__VA_ARGS__)
#define SAT_TRACE(...) ::Satellite::Log::getClientLogger()->trace(__VA_ARGS__)