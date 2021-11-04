#include "../include/FishException.h"

const char *FishException::what() const noexcept
{
    return "You've caught the fish! You win!";
}