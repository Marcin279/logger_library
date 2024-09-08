#pragma once
#include <string>

class RESTAPIClient {
private:
    std::string endpoint;

public:
    RESTAPIClient(const std::string& endpoint)
        : endpoint(endpoint) {}

    void post(const std::string& log);
};
