#pragma once

#include <string>

#include "LogDestination.hpp"


class NetworkLogger : public LogDestination {
public:
    NetworkLogger() = default;
    NetworkLogger(const std::string endpoint, const RESTAPIClient& apiClient) : endpoint(endpoint), apiClient(apiClient) {};
    ~NetworkLogger() = default;
    void log(const std::string &message) override;

private:
    std::string endpoint;
    RESTAPIClient apiClient;
};