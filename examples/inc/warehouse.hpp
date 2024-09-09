#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Logger.hpp"

using String = std::string;

struct Product {
    String name;
    String description;

    Product(const String& name, const String& description)
        : name(name), description(description) {}
};


class Warehouse {
public:
    Warehouse(Logger& logger) : logger(logger) {}

    void addCategory(const String& categoryName);
    void addProduct(const String& categoryName, const String& productName, const String& productDescription);
    void listCategory(const String& categoryName);
    void removeProduct(const String& categoryName, const String& productName);
    void removeCategory(const String& categoryName);

private:
    std::map<String, std::vector<Product>> categories;
    Logger logger;
};