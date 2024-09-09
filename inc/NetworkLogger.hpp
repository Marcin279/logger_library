#pragma once

#include <string>
#include "LogDestination.hpp"
#include "RESTAPIClient.hpp"
#include <memory>


class NetworkLogger : public LogDestination {
public:
    NetworkLogger() = default;
    NetworkLogger(const std::string serverUrl);
    void log(LogLevel logLevel, const std::string& message) override;

    ~NetworkLogger() = default;

private:
    std::string serverUrl;
    std::shared_ptr<RESTAPIClient> apiClient;
};