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

    Logger(const std::string& logFile,
           const std::string& serverUrl,
           LogDestinationOption destinationOption = LogDestinationOption::BOTH);

	void log(LogLevel logLevel, const std::string& message);
    void setLogTimeFormat(const std::string& timeFormat);

    ~Logger() = default;


private:
    void initializeDestinations();
    void addFileDestination();
    void addNetworkDestination();

    std::string serverUrl;
    std::string logFile;
    LogDestinationOption destinationOption;
    LogFormatter formatter;
    LogDestinationManager destinationManager;
};
