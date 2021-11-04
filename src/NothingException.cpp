#include "../include/NothingException.h"

const char *NothingException::what() const noexcept {
    return "You've catch nothing! Try again!\n";
}