#pragma once

#include <string>

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#define SPDLOG_DEBUG_ON
#define SPDLOG_TRACE_ON

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <memory>

namespace VEngine {
	namespace Utilities {
		struct Logger {
			Logger() {
				/* Setup the logging to the console. */
				auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
				console_sink->set_level(spdlog::level::info);
				console_sink->set_pattern("[%H:%M:%S] [%^%l%$] %v");

				/* Setup the file logging */
				auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("Logs/spdlog.txt", true);
				file_sink->set_level(spdlog::level::trace);

				/* Create the logger to use both console logger and the file logger */
				this->_logger = std::make_shared<spdlog::logger>(spdlog::logger("VEngine", { console_sink, file_sink }));
				this->_logger->set_level(spdlog::level::debug);

				spdlog::register_logger(_logger);
			}

			std::shared_ptr<spdlog::logger> _logger;
		};

		inline Logger Log;

		inline bool GetLaunchOption(const uint32_t argc, char* argv[], const std::string& option) {
			bool found = false;

			/* First argument will be the location of this exectuable so we skip it. If there's no other option after that then return false */
			if (argc <= 1) {
				Log._logger->info("No commandline options found");
				return found;
			}

			/* Loop over all the passed arguments and see if it is equal to the option variable. If it is then return true because it has been found */
			for (uint32_t i = 1; i < argc; i++) {
				SPDLOG_DEBUG("[{0}] Launch option - {1}", i, argv[i]);
				if (argv[i] == option) {
					Log._logger->info("Found Launch Option: {}", option.c_str());
					found = true;
				}
			}

			return found;
		}
	}
}