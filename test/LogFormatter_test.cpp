#include <gtest/gtest.h>
#include "LogFormatter.hpp"


TEST(LogFormatterTest, FormatLogWithDefaultTime) {
    LogFormatter formatter;
    std::string message = "Test log message";
    std::string result = formatter.format(LogLevel::DEBUG, message);

    EXPECT_NE(result.find("DEBUG"), std::string::npos);

    EXPECT_NE(result.find(message), std::string::npos);

    std::time_t now = std::time(nullptr);
    char buf[80];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d", std::localtime(&now));
    EXPECT_NE(result.find(buf), std::string::npos);
}

TEST(LogFormatterTest, FormatLogWithErrorLevel) {
    LogFormatter formatter;
    std::string message = "Error occurred";
    std::string result = formatter.format(LogLevel::ERROR, message);

    EXPECT_NE(result.find("ERROR"), std::string::npos);

    EXPECT_NE(result.find(message), std::string::npos);
}

TEST(LogFormatterTest, FormatLogWithCustomTimeFormat) {
    LogFormatter formatter;

    LogFormatter::setTimeFormat("%H:%M:%S");

    std::string message = "Custom time format";
    std::string result = formatter.format(LogLevel::INFO, message);

    EXPECT_NE(result.find("INFO"), std::string::npos);

    EXPECT_NE(result.find(message), std::string::npos);

    std::time_t now = std::time(nullptr);
    char buf[80];
    std::strftime(buf, sizeof(buf), "%H:%M:%S", std::localtime(&now));
    EXPECT_NE(result.find(buf), std::string::npos);

    LogFormatter::setTimeFormat("%Y-%m-%d %H:%M:%S");
}

TEST(LogFormatterTest, FormatLogWithUnknownLevel) {
    LogFormatter formatter;
    std::string message = "Unknown log level";
    std::string result = formatter.format(LogLevel::UNKNOWN, message);

    EXPECT_NE(result.find("UNKNOWN"), std::string::npos);
    EXPECT_NE(result.find(message), std::string::npos);
}
