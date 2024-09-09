#pragma once

#include <fstream>
#include <string>
#include "LogLevel.hpp"
#include "Logger.hpp"
#include "LogFormatter.hpp"

class FileLogger : public LogDestination {
public:
    FileLogger() = default;
    FileLogger(const std::string& filename) : filename(filename) {}
    FileLogger(const std::string& filename, int maxSize) : filename(filename), maxSize(maxSize) {}

    void log(LogLevel logLevel, const std::string& message) override;

    void rotateFiles();

    ~FileLogger() = default;

private:
    std::string filename;
    int maxSize = 10 * 1024 * 1024;
};