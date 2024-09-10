#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "LogDestinationManager.hpp"
#include "mocks/MockLogDestination.hpp"

using ::testing::_;
using ::testing::Eq;
using ::testing::Return;
using ::testing::Exactly;

class TestableLogDestinationManager : public LogDestinationManager {
public:
    using LogDestinationManager::getDestinations;
};

class LogDestinationManagerTest : public ::testing::Test, LogDestinationManager {
protected:
    TestableLogDestinationManager manager;
    std::shared_ptr<MockLogDestination> fileDestination;

    void SetUp() override {
        fileDestination = std::make_shared<MockLogDestination>();
    }
};

TEST_F(LogDestinationManagerTest, AddFileDestination) {
    manager.addDestination(fileDestination, DestinationType::FILE);

    EXPECT_EQ(manager.getDestinations().size(), 1);
}

TEST_F(LogDestinationManagerTest, LogToAllDestinations_FileOnly) {
    manager.addDestination(fileDestination, DestinationType::FILE);

    EXPECT_CALL(*fileDestination, log(LogLevel::INFO, "Test message"))
        .Times(Exactly(1));

    manager.logToAllDestinations(LogLevel::INFO, "Test message");
}

TEST_F(LogDestinationManagerTest, RemoveFileDestination) {
    manager.addDestination(fileDestination, DestinationType::FILE);

    manager.removeDestination(DestinationType::FILE);

    EXPECT_EQ(manager.getDestinations().size(), 0);
}
