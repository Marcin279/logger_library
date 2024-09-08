#pragma once

#include "LogFormatter.hpp"
#include "LogDestinationManager.hpp"
#include "LogLevel.hpp"

class Logger {
public:
    Logger(LogLevel level, const LogFormatter& formatter, const LogDestinationManager& destinationManager)
    : level(level), formatter(formatter), destinationManager(destinationManager) {}

	void log(LogLevel logLevel, const std::string& message);
    ~Logger() = default;

private:
    LogLevel level;
    LogFormatter formatter;
    LogDestinationManager destinationManager;
};
