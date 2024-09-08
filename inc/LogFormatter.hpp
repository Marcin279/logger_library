#pragma once

#include <string>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>

#include "LogLevel.hpp"

class LogFormatter {
public:
    // Statyczne metody zapewniają jednolitość logów w całej aplikacji oraz brak potrzeby tworzenia obiektów
	static std::string format(LogLevel logLevel, const std::string& message);
    static void setTimeFormat(const std::string& format);

private:
    static std::string timeFormat;
};