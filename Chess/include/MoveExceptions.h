#pragma once
#include <exception>
#include <string>

class InvalidMoveException : public std::exception {
private:
    std::string message;
public:
    explicit InvalidMoveException(const std::string& msg);
    const char* what() const noexcept override;
};

class EmptyQueueException : public std::exception {
private:
    std::string message;
public:
    explicit EmptyQueueException(const std::string& msg);
    const char* what() const noexcept override;
};
