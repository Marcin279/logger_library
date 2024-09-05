#include <gtest/gtest.h>
#include "../inc/LogLevel.hpp"

TEST(ColorEnumTest, EnumValues) {
    // Check if the values are what we expect
    EXPECT_EQ(static_cast<int>(LogLevel::DEBUG), 0);
    EXPECT_EQ(static_cast<int>(LogLevel::INFO), 1);
    EXPECT_EQ(static_cast<int>(LogLevel::WARNING), 2);
    EXPECT_EQ(static_cast<int>(LogLevel::ERROR), 3);
    EXPECT_EQ(static_cast<int>(LogLevel::FATAL), 4);
    EXPECT_EQ(static_cast<int>(LogLevel::TRACE), 5);
    EXPECT_EQ(static_cast<int>(LogLevel::UNKNOWN), 99);
}

TEST(LogLevelTest, LogLevelToStringTest) {
    // Check if the values are what we expect
    EXPECT_EQ(logLevelToString(LogLevel::DEBUG), "DEBUG");
    EXPECT_EQ(logLevelToString(LogLevel::INFO), "INFO");
    EXPECT_EQ(logLevelToString(LogLevel::WARNING), "WARNING");
    EXPECT_EQ(logLevelToString(LogLevel::ERROR), "ERROR");
    EXPECT_EQ(logLevelToString(LogLevel::FATAL), "FATAL");
    EXPECT_EQ(logLevelToString(LogLevel::TRACE), "TRACE");
    EXPECT_EQ(logLevelToString(LogLevel::UNKNOWN), "UNKNOWN");
}