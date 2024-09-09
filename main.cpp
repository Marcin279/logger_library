#include <iostream>
#include <cstdlib>

#include <Logger.hpp>
#include "LogLevel.hpp"


int main() {
    std::cout << "Start" << std::endl;

/*
    Logger logger(LogLevel::INFO, LogDestinationOption::FILE, "logs.txt", "http://log_server:8090");

    logger.log(LogLevel::INFO, "This is a file-only informational message.");
    logger.log(LogLevel::ERROR, "This is a file-only error message.");

    std::cout << "Done" << std::endl;
*/

    Logger logger0(LogDestinationOption::NETWORK, "logs.txt", "http://log_server:8090");

    logger0.log(LogLevel::INFO, "This is a Network-only informational message.");
    logger0.log(LogLevel::ERROR, "This is a Network-only error message.");

    Logger logger(LogDestinationOption::BOTH, "logs.txt", "http://log_server:8090");
    logger.setLogTimeFormat("%d-%m-%Y %H:%M:%S");
    logger.log(LogLevel::INFO, "This is a Network and File informational message.");
    logger.log(LogLevel::ERROR, "This is a Network and File error message.");

    std::cout << "Done" << std::endl;

    return EXIT_SUCCESS;
}