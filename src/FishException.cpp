#include "../include/FishException.h"

const char *FishException::what() const noexcept {
    return "You've catch the fish! You win!\n";
}