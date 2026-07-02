#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger {
public:
    void info(const std::string& message);
    void warn(const std::string& message);
    void error(const std::string& message);
};

#endif