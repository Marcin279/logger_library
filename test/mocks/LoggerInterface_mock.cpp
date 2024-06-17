#include <gmock/gmock.h>

#include "../../inc/LoggerInterface.hpp"

class MockLogger : public LoggerInterface {
    public:
        MOCK_METHOD(void, log, (LogLevel logLevel, const std::string& message), (override));
        MOCK_METHOD(void, setFileLogging, (bool enabled), (override));
        MOCK_METHOD(void, setRemoteLogging, (bool enable, const std::string& serverURL), (override));
        ~MockLogger();
};
