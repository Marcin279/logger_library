#include "FileLogger.hpp"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void FileLogger::log(LogLevel logLevel, const std::string& message)  {
    std::ofstream logFile(filename, std::ios_base::app);

    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
        return;
    }

    std::string formattedMessage = LogFormatter::format(logLevel, message);
    logFile << formattedMessage << std::endl;

    logFile.close();
    if (fs::file_size(filename) > maxSize) {
        rotateFiles();
    }
}


void FileLogger::rotateFiles() {
    std::string backupFilename = filename + ".1";

    if (fs::exists(backupFilename)) {
        fs::remove(backupFilename);
    }

    fs::rename(filename, backupFilename);

    std::ofstream newLogFile(filename);
    if (!newLogFile.is_open()) {
        std::cerr << "Failed to create new log file: " << filename << std::endl;
    } else {
        std::cout << "Rotated log file: " << filename << " -> " << backupFilename << std::endl;
    }
    newLogFile.close();
}