#include <iostream>
#include <cstdlib>
#include "NetworkLogger.hpp"
#include "LogLevel.hpp"


int main() {
    std::cout << "Start" << std::endl;

    // Testy NetworkLogger
    NetworkLogger logger("http://log_server:8090");

    // Przykładowe logi do wysłania
    logger.log(LogLevel::INFO, "This is an informational message.");
    logger.log(LogLevel::ERROR, "This is an error message.");


    std::cout << "Done" << std::endl;

    return EXIT_SUCCESS;
}