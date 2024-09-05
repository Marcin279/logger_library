#pragma once

#include <string>

// Dodaj templete do generorowania stringa z opisem log levelu

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

