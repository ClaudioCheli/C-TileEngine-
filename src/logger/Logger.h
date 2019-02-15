/*
 * Logger.h
 *
 *  Created on: 10 feb 2019
 *      Author: Claudio Cheli
 */

#ifndef SRC_LOGGER_LOGGER_H_
#define SRC_LOGGER_LOGGER_H_

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"

class Logger{

public:
	static void Init();

	inline static std::shared_ptr<spdlog::logger>& getLogger(){ return Logger::logger; }

private:

	static std::shared_ptr<spdlog::logger> logger;

};


#define LOG_DEBUG(...) 	::Logger::getLogger()->debug(__VA_ARGS__)
#define LOG_INFO(...) 	::Logger::getLogger()->info(__VA_ARGS__)
#define LOG_ERROR(...) 	::Logger::getLogger()->error(__VA_ARGS__)

#endif /* SRC_LOGGER_LOGGER_H_ */
