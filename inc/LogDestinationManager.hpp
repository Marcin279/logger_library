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

    ~LogDestinationManager() = default;

protected:
    // For test only
    const std::vector<std::shared_ptr<LogDestination>>& getDestinations() const { return destinations; }

private:
    std::vector<std::shared_ptr<LogDestination>> destinations;
    std::vector<DestinationType> destinationTypes;
};