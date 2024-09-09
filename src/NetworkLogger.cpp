#include "NetworkLogger.hpp"
#include "LogLevel.hpp"

#include <iostream>
#include <string>


NetworkLogger::NetworkLogger(const std::string serverUrl) : serverUrl(serverUrl) {
    apiClient = std::make_shared<RESTAPIClient>(serverUrl);
}

void NetworkLogger::log(LogLevel logLevel, const std::string& message) {

    if (!apiClient->sendLog(message)) {
        std::cerr << "Failed to send log message to the server." << std::endl;
    }
}