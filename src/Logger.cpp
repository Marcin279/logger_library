#include "Logger.hpp"


Logger::Logger(const std::string& logFile,
               const std::string& serverUrl,
               LogDestinationOption destinationOption)
    : logFile(logFile), serverUrl(serverUrl), destinationOption(destinationOption) {

    formatter = LogFormatter();
    destinationManager = LogDestinationManager();

    if (this->destinationOption == LogDestinationOption::FILE || this->destinationOption == LogDestinationOption::BOTH) {
        std::shared_ptr<LogDestination> fileLogger = std::make_shared<FileLogger>(this->logFile);
        destinationManager.addDestination(fileLogger, DestinationType::FILE);
    }

    if (this->destinationOption == LogDestinationOption::NETWORK || this->destinationOption == LogDestinationOption::BOTH) {
        std::shared_ptr<LogDestination> networkLogger = std::make_shared<NetworkLogger>(this->serverUrl);
        destinationManager.addDestination(networkLogger, DestinationType::NETWORK);
    }
}


void Logger::log(LogLevel logLevel, const std::string& message) {
    std::string formattedMessage = formatter.format(logLevel, message);
    destinationManager.logToAllDestinations(logLevel, formattedMessage);
}

void Logger::setLogTimeFormat(const std::string& timeFormat) {
    LogFormatter::setTimeFormat(timeFormat);
}