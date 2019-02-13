/*
 * Logger.cpp
 *
 *  Created on: 10 feb 2019
 *      Author: Claudio Cheli
 */

#include "Logger.h"

std::shared_ptr<spdlog::logger> Logger::logger;

void Logger::Init() {
	spdlog::set_level(spdlog::level::trace);
	Logger::logger = spdlog::stdout_color_mt("TELogger");
}
