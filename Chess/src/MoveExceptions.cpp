#include "MoveExceptions.h"

// InvalidMoveException implementation
InvalidMoveException::InvalidMoveException(const std::string& msg) : message(msg) {}

const char* InvalidMoveException::what() const noexcept {
    return message.c_str();
}

// EmptyQueueException implementation
EmptyQueueException::EmptyQueueException(const std::string& msg) : message(msg) {}

const char* EmptyQueueException::what() const noexcept {
    return message.c_str();
}
