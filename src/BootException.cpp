#include "../include/BootException.h"

const char *BootException::what() const noexcept {
    return "You've catch the boot :(\n";
}