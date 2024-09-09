#include "Logger.hpp"


Logger::Logger(LogLevel level,
               LogDestinationOption destinationOption,
               const std::string& logFile,
               const std::string& serverUrl) : level(level) {

    formatter = LogFormatter();
    destinationManager = LogDestinationManager();

    if (destinationOption == LogDestinationOption::FILE || destinationOption == LogDestinationOption::BOTH) {
        std::shared_ptr<LogDestination> fileLogger = std::make_shared<FileLogger>(logFile);
        destinationManager.addDestination(fileLogger, DestinationType::FILE);
    }

    if (destinationOption == LogDestinationOption::NETWORK || destinationOption == LogDestinationOption::BOTH) {
        std::shared_ptr<LogDestination> networkLogger = std::make_shared<NetworkLogger>(serverUrl);
        destinationManager.addDestination(networkLogger, DestinationType::NETWORK);
    }
}


void Logger::log(LogLevel logLevel, const std::string& message) {
    if (static_cast<int>(logLevel) < static_cast<int>(level)) {
        return;
    }

    std::string formattedMessage = formatter.format(logLevel, message);
    destinationManager.logToAllDestinations(logLevel, formattedMessage);
}

void Logger::setLogTimeFormat(const std::string& timeFormat) {
    LogFormatter::setTimeFormat(timeFormat);
}