#pragma once

#include "LogDestination.hpp"
#include "LogLevel.hpp"
#include <vector>
#include <memory>


enum class DestinationType {
    FILE,
    NETWORK
};

class LogDestinationManager {
public:
    void addDestination(std::shared_ptr<LogDestination> destination, DestinationType type);
    void removeDestination(DestinationType type);

    void logToAllDestinations(LogLevel logLevel, const std::string& message);
    void logToFileOnly(LogLevel logLevel, const std::string& message);
    void logToNetworkOnly(LogLevel logLevel, const std::string& message);

    const std::vector<std::shared_ptr<LogDestination>>& getDestinations() const { return destinations; }


    ~LogDestinationManager() = default;


private:
    std::vector<std::shared_ptr<LogDestination>> destinations;
    std::vector<DestinationType> destinationTypes;
};