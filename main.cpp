#include <iostream>
#include <cstdlib>

#include <Logger.hpp>
#include "LogLevel.hpp"
#include "Warehouse.hpp"

int main() {
    std::cout << "Start" << std::endl;

    // Tworzenie i konfiguracja loggera
    Logger logger("warehouse_logs.txt", "http://log_server:8090", LogDestinationOption::BOTH);
    logger.setLogTimeFormat("%d-%m-%Y %H:%M:%S");

    Warehouse warehouse(logger);

    warehouse.addCategory("Electronics");
    warehouse.addCategory("Books");
    warehouse.addProduct("Electronics", "Smartphone", "A smartphone with 128GB storage");
    warehouse.addProduct("Electronics", "Laptop", "A high-performance laptop");
    warehouse.addProduct("Books", "C++ Programming", "A comprehensive guide to C++ programming");

    warehouse.listCategory("Electronics");
    warehouse.listCategory("Books");

    warehouse.removeProduct("Electronics", "Smartphone");

    warehouse.listCategory("Electronics");

    warehouse.removeCategory("Books");

    std::cout << "Done" << std::endl;

    return EXIT_SUCCESS;
}