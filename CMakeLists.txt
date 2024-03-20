cmake_minimum_required(VERSION 3.22)  # CMake version check
project(logger_app)
set(CMAKE_CXX_STANDARD 20)            # Enable c++20 standard

# Find Boost
#find_package(Boost REQUIRED)

# Include Google Test Framework
#add_subdirectory(lib/googletest)

#include_directories(
#        googletest/googlemock/include
#        googletest/googletest/include
#)

# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES main.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(logger_app ${SOURCE_FILES})




## =================================================================================================================
#cmake_minimum_required(VERSION 3.22)
#project(matlab_2_clion)
#
#set(CMAKE_CXX_STANDARD 20)
#
## Miejsca w których kompilator ma szukać plików nagłówkowych
#include_directories(include
#        googletest/googlemock/include
#        googletest/googletest/include)
#
#
## Wszystkie pliki projektu z rozszerzeniem .cpp
#set(SOURCE_FILES
#        src/calculator.cpp
#        src/md5.cpp
#)
#
## Dodawanie poszczególnych testów
#set(TEST_SOURCES
#        test/
#        test/main_test.cpp
#        test/calculator_test.cpp
#        test/md5_test.cpp
#        test/md5_fixture_test.cpp
#        test/md5_fixture2_test.cpp
#        include/threads.hpp
#)
#
##dodaje bibliotekę Google Test, kompiluje ją z użyciem CMakeLists.txt z folderu googletest-master
#add_subdirectory(googletest)
#link_libraries(gmock)
#
##Tworzy konfigurację o nazwie konfig_run (nazwę możemy dowolnie zmienić)
## do której dołącza plik main.cpp z funkcją main()
#add_executable(config_run ${SOURCE_FILES} main.cpp
#        include/threads.hpp)
#
##Tworzy konfigurację o nazwie konfig_test służącą do uruchamiania testów jednostkowych
#add_executable(config_test ${SOURCE_FILES} ${TEST_SOURCES}
#        include/threads.hpp)