#include "gtest/gtest.h"
#include <memory>
#include "Logger.hpp"
#include "LogLevel.hpp"
#include "FileLogger.hpp"
#include "NetworkLogger.hpp"
#include "MockLogDestination.hpp"

TEST(LoggerTest, LogToFileOnly) {
    Logger logger("test_logs.txt", "http://log_server:8090", LogDestinationOption::FILE);

    logger.log(LogLevel::INFO, "This is a test log for file.");

    std::ifstream logFile("test_logs.txt");
    ASSERT_TRUE(logFile.is_open());

    std::string logMessage;
    std::getline(logFile, logMessage);

    EXPECT_NE(logMessage.find("This is a test log for file."), std::string::npos);

    logFile.close();
}

TEST(LoggerTest, LogToBothFileAndNetwork) {
    Logger logger("test_logs_both.txt", "http://log_server:8090", LogDestinationOption::BOTH);

    logger.log(LogLevel::INFO, "This is a test log for both file and network.");

    std::ifstream logFile("test_logs_both.txt");
    ASSERT_TRUE(logFile.is_open());

    std::string logMessage;
    std::getline(logFile, logMessage);

    EXPECT_NE(logMessage.find("This is a test log for both file and network."), std::string::npos);

    logFile.close();
}
