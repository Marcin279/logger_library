#pragma once

#include <gmock/gmock.h>
#include <LogDestination.hpp>  // Interfejs LogDestination, który mockujemy

class MockLogDestination : public LogDestination {
public:
    MOCK_METHOD(void, log, (LogLevel logLevel, const std::string& message), (override));
};

