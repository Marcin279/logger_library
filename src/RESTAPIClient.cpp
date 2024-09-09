#include "RESTAPIClient.hpp"
#include <iostream>

RESTAPIClient::RESTAPIClient(const std::string& serverUrl)
    : serverUrl(serverUrl), curlHandle(nullptr) {
    initCurl();
}

RESTAPIClient::~RESTAPIClient() {
    cleanupCurl();
}

bool RESTAPIClient::initCurl() {
    curlHandle = curl_easy_init();
    return curlHandle != nullptr;
}

void RESTAPIClient::cleanupCurl() {
    if (curlHandle) {
        curl_easy_cleanup(curlHandle);
        curlHandle = nullptr;
    }
}

bool RESTAPIClient::sendLog(const std::string& logMessage) {
    if (!curlHandle) {
        std::cerr << "CURL is not initialized." << std::endl;
        return false;
    }

    curl_easy_setopt(curlHandle, CURLOPT_URL, serverUrl.c_str());
    curl_easy_setopt(curlHandle, CURLOPT_POST, 1L);
    curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDS, logMessage.c_str());

    CURLcode res = curl_easy_perform(curlHandle);

    if (res != CURLE_OK) {
        std::cerr << "CURL error: " << curl_easy_strerror(res) << std::endl;
        return false;
    }

    return true;
}
