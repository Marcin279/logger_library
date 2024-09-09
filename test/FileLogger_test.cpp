#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>
#include "FileLogger.hpp"

namespace fs = std::filesystem;

TEST(FileLoggerTest, LogToFile) {
    std::string testFile = "test_log.log";

    FileLogger fileLogger(testFile);

    // Usuwanie pliku, jeśli istnieje
    if (fs::exists(testFile)) {
        fs::remove(testFile);
    }

    fileLogger.log(LogLevel::INFO, "This is a test log message.");

    EXPECT_TRUE(fs::exists(testFile));

    std::ifstream logFile(testFile);
    std::string line;
    std::getline(logFile, line);

    std::string expectedMessage = "This is a test log message.";

    if (!expectedMessage.empty() && expectedMessage.back() == '\n') {
        expectedMessage.pop_back();
    }

    EXPECT_EQ(line, expectedMessage);

    logFile.close();
    fs::remove(testFile);
}

TEST(FileLoggerTest, LogFileRotation) {
    std::string testFile = "test_rotation.log";

    FileLogger fileLogger(testFile, 1024);

    // Usuwanie pliku i jego backupu jeśli istnieją
    if (fs::exists(testFile)) {
        fs::remove(testFile);
    }
    if (fs::exists(testFile + ".1")) {
        fs::remove(testFile + ".1");
    }

    // Wypełnianie pliku aby osiągnąć maksymalny rozmiar
    for (int i = 0; i < 100; ++i) {
        fileLogger.log(LogLevel::INFO, "Filling up the log file.");
    }

    // Sprawdzanie czy plik został zrotowany
    EXPECT_TRUE(fs::exists(testFile + ".1"));

    EXPECT_TRUE(fs::exists(testFile));

    fs::remove(testFile);
    fs::remove(testFile + ".1");
}

TEST(FileLoggerTest, InvalidFileName) {
    std::string invalidFile = "/invalid_path/test_log.log";

    FileLogger fileLogger(invalidFile);

    EXPECT_NO_THROW(fileLogger.log(LogLevel::ERROR, "Attempting to log to invalid file path."));
}

