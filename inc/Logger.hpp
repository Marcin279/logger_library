#pragma once

#include "LogFormatter.hpp"
#include "LogDestinationManager.hpp"
#include "LogLevel.hpp"
#include "FileLogger.hpp"
#include "NetworkLogger.hpp"

#include <memory>
#include <string>

enum class LogDestinationOption {
    FILE,
    NETWORK,
    BOTH
};

class Logger {
public:

    Logger(LogLevel level,
           LogDestinationOption destinationOption = LogDestinationOption::BOTH,
           const std::string& logFile = "logs.txt",
           const std::string& serverUrl = "http://log_server:8090");

	void log(LogLevel logLevel, const std::string& message);
    void setLogTimeFormat(const std::string& timeFormat);

    ~Logger() = default;

private:
    LogLevel level;
    LogFormatter formatter;
    LogDestinationManager destinationManager;
};
