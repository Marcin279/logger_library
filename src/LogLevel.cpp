#include <string>
#include "LogLevel.hpp"

std::string logLevelToString(LogLevel logLevel)
{
    switch (logLevel) {
        case LogLevel::DEBUG:
            return "DEBUG";
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::FATAL:
            return "FATAL";
        case LogLevel::TRACE:
            return "TRACE";
        default:
            return "UNKNOWN";
    }
}