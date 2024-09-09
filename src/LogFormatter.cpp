#include "LogFormatter.hpp"

std::string LogFormatter::timeFormat = "%Y-%m-%d %H:%M:%S";

std::string LogFormatter::format(LogLevel level, const std::string& message) {
    std::string levelStr = logLevelToString(level);

    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&currentTime), timeFormat.c_str());
    oss << " [" << levelStr << "] " << message << std::endl;
    return oss.str();
}

void LogFormatter::setTimeFormat(const std::string& format) {
    timeFormat = format;
}