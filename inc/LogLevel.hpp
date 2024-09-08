#pragma once

#include <string>

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL,
    TRACE,
    UNKNOWN = 99
};

std::string logLevelToString(LogLevel level);

template<LogLevel level>
std::string generateLogLevelString() {
    return logLevelToString(level);
}

