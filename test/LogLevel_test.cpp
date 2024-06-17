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
}