cmake_minimum_required(VERSION 3.22)  # CMake version check
project(logger_library)

set(CMAKE_CXX_STANDARD 20)            # Enable c++20 standard
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable testing
enable_testing()

# Add Google test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add Curl package
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})

# Add directories
include_directories(inc)
include_directories(test)
include_directories(test/mocks)

include_directories(examples/inc)

set(SOURCE_FILES src/Logger.cpp
        src/LogFormatter.cpp
        src/LogLevel.cpp
        src/LogDestinationManager.cpp
        src/FileLogger.cpp
        src/NetworkLogger.cpp
        src/RESTAPIClient.cpp
        examples/src/warehouse.cpp
)

set(TEST_SOURCES
        test/main_test.cpp
        test/Logger_test.cpp
        test/LogLevel_test.cpp
        test/LogFormatter_test.cpp
        test/FileLogger_test.cpp
        test/LogDestinationManager_test.cpp
        test/mocks/MockLogDestination.hpp
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(logger_library_run ${SOURCE_FILES} main.cpp)

# Link libcurl to the main executable
target_link_libraries(logger_library_run ${CURL_LIBRARIES})

# Add executable target for tests
add_executable(logger_library_test ${SOURCE_FILES} ${TEST_SOURCES})

## Link GoogleTest libraries to the test executable
target_link_libraries(logger_library_test
        GTest::gtest
        GTest::gmock
        pthread
        ${CURL_LIBRARIES}
)

add_test(NAME logger_library_test, COMMAND logger_library_test)