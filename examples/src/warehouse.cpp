#include "warehouse.hpp"
#include "LogLevel.hpp"


void Warehouse::addCategory(const String& categoryName) {
    if (categories.find(categoryName) == categories.end()) {
        categories[categoryName] = std::vector<Product>();
        logger.log(LogLevel::INFO, "Added new category: " + categoryName);
        std::cout << "Category added: " << categoryName << std::endl;
    } else {
        logger.log(LogLevel::WARNING, "Category already exists: " + categoryName);
        std::cout << "Category already exists: " << categoryName << std::endl;
    }
}


void Warehouse::addProduct(const String& categoryName, const String& productName, const std::string& productDescription) {
    if (categories.find(categoryName) != categories.end()) {
        categories[categoryName].push_back(Product(productName, productDescription));
        logger.log(LogLevel::INFO, "Added product '" + productName + "' to category '" + categoryName + "'");
        std::cout << "Product added: " << productName << " to category: " << categoryName << std::endl;
    } else {
        logger.log(LogLevel::ERROR, "Category does not exist: " + categoryName);
        std::cout << "Category does not exist: " + categoryName << std::endl;
    }
}



void Warehouse::listCategory(const String& categoryName) {
    if (categories.find(categoryName) != categories.end()) {
        std::cout << "Category: " << categoryName << std::endl;
        for (const auto& product : categories[categoryName]) {
            std::cout << "- " << product.name << ": " << product.description << std::endl;
        }
        logger.log(LogLevel::INFO, "Listed products in category: " + categoryName);
    } else {
        logger.log(LogLevel::ERROR, "Category does not exist: " + categoryName);
        std::cout << "Category does not exist: " + categoryName << std::endl;
    }
}


void Warehouse::removeProduct(const String& categoryName, const std::string& productName) {
    if (categories.find(categoryName) != categories.end()) {
        auto& products = categories[categoryName];
        auto it = std::remove_if(products.begin(), products.end(), [&](const Product& product) {
            return product.name == productName;
        });
        if (it != products.end()) {
            products.erase(it, products.end());
            logger.log(LogLevel::INFO, "Removed product: " + productName + " from category: " + categoryName);
            std::cout << "Product removed: " << productName << std::endl;
        } else {
            logger.log(LogLevel::WARNING, "Product not found: " + productName);
            std::cout << "Product not found: " + productName << std::endl;
        }
    } else {
        logger.log(LogLevel::ERROR, "Category does not exist: " + categoryName);
        std::cout << "Category does not exist: " + categoryName << std::endl;
    }
}


void Warehouse::removeCategory(const String& categoryName) {
    if (categories.find(categoryName) != categories.end()) {
        categories.erase(categoryName);
        logger.log(LogLevel::INFO, "Removed category: " + categoryName);
        std::cout << "Category removed: " + categoryName << std::endl;
    } else {
        logger.log(LogLevel::ERROR, "Category does not exist: " + categoryName);
        std::cout << "Category does not exist: " + categoryName << std::endl;
    }
}