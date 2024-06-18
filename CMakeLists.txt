cmake_minimum_required(VERSION 3.22)  # CMake version check
project(logger_library)

set(CMAKE_CXX_STANDARD 20)            # Enable c++20 standard
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find boost lib
#set(Boost_COMPONENTS system filesystem)
#find_package(Boost REQUIRED COMPONENTS ${Boost_COMPONENTS})
#include_directories(${Boost_INCLUDE_DIRS})

# Enable testing
enable_testing()

# Add Google test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add includes
include_directories(inc)

set(SOURCE_FILES src/Logger.cpp
                 src/LoggerInterface.cpp
)

set(TEST_SOURCES
        test/main_test.cpp
        test/Logger_test.cpp
        test/LogLevel_test.cpp
)

# Add GoogleTest as a subdirectory
#add_subdirectory(../gtest/googletest-release-1.11.0 gtest)
# Link GoogleTest libraries
link_libraries(gtest)
link_libraries(gmock)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(logger_library_run ${SOURCE_FILES} main.cpp)

# Add executable target for tests
add_executable(logger_library_test ${SOURCE_FILES} ${TEST_SOURCES})
#
## Link GoogleTest libraries to the test executable
target_link_libraries(logger_library_test ${GTEST_LIBRARIES} pthread)

add_test(NAME logger_library_test, COMMAND logger_library_test)