//
// Created by marci on 25.03.2024.
//

#ifndef LOGGER_LIBRARY_LOGGERINTERFACE_HPP
#define LOGGER_LIBRARY_LOGGERINTERFACE_HPP

#include <string>
#include "LogLevel.hpp"

class LoggerInterface {
    virtual void log(LogLevel logLevel, const std::string& message) = 0;
    virtual void setFileLogging(bool enabled) = 0;
    virtual void setRemoteLogging(bool enable, const std::string& serverURL) = 0;
    virtual ~LoggerInterface() {}
};

#endif //LOGGER_LIBRARY_LOGGERINTERFACE_HPP
