#pragma once

#include <string>
#include <curl/curl.h>

class RESTAPIClient {
public:
    RESTAPIClient(const std::string& serverUrl);
    ~RESTAPIClient();

    bool sendLog(const std::string& logMessage);

private:
    std::string serverUrl;
    CURL* curlHandle;

    bool initCurl();
    void cleanupCurl();
};

