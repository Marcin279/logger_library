#pragma once
#include <string>
#include "LogLevel.hpp"

class LogDestination {
public:
    virtual ~LogDestination() = default;

    virtual void log(LogLevel logLevel, const std::string& message) = 0;
};