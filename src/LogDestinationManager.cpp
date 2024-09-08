#include <LogDestinationManager.hpp>
#include <string>
#include <algorithm>

void LogDestinationManager::logToAllDestinations(LogLevel logLevel, const std::string& message) {
    for (auto& destination : destinations) {
        destination->log(logLevel, message);
    }
}

void LogDestinationManager::addDestination(std::shared_ptr<LogDestination> destination, DestinationType type) {
    destinations.push_back(destination);
    destinationTypes.push_back(type);
}

void LogDestinationManager::removeDestination(DestinationType type) {
    // Znajdujemy wszystkie destynacje o podanym typie i usuwamy je
    auto it = std::remove_if(destinations.begin(), destinations.end(),
        [&, index = 0](const std::shared_ptr<LogDestination>& destination) mutable {
            if (destinationTypes[index] == type) {
                destinationTypes.erase(destinationTypes.begin() + index);
                return true;  // Oznaczamy ten element do usunięcia
            }
            ++index;
            return false;
        });

    destinations.erase(it, destinations.end());
}


void LogDestinationManager::logToFileOnly(LogLevel logLevel, const std::string& message) {
    for (size_t i = 0; i < destinations.size(); ++i) {
        if (destinationTypes[i] == DestinationType::FILE) {
            destinations[i]->log(logLevel, message);
        }
    }
}

void LogDestinationManager::logToNetworkOnly(LogLevel logLevel, const std::string& message) {
    for (size_t i = 0; i < destinations.size(); ++i) {
        if (destinationTypes[i] == DestinationType::NETWORK) {
            destinations[i]->log(logLevel, message);
        }
    }
}
